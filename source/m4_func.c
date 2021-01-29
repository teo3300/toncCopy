#include "m4_func.h"

u16 *vid_page = vid_mem;   // create a pointer to 0x0600:0000 full instruction u16 *vid_page = ((u16*)(0x06000000))
                           //This value change at every frame (switch from 0x0600:0000 to 0x0600:A000)

u16 *vid_flip(){
    vid_page = MEM_MAP_16((u32)vid_page ^ VID_FLIP);
    REG_DISPCNT ^= DCNT_PAGE;
    return vid_page;
}

void m4_plot(int x, int y, u8 clrid){
    u16 *dst = (vid_page+((x + M4_WIDTH*y )>>1)); //dst point to the current vidpage array (>>1) due to the u16->u8 conversion
    if(x&1){
        *dst = (*dst& 0xFF) | (clrid<<8);    //index is odd -> higher half byte
    }else{
        *dst = (*dst&~0xFF) | (clrid);       //index is even -> lower half
    }
}

void m4_fill(u8 clrid){
    int i, paint = (clrid<<8)+clrid;
    for(i=0;i<VRAM_PAGE_SIZE;i++)
        *(vid_page+(i>>1)) = paint;
}
