#include "GBA_main.h"
#include <string.h>     // needed to memcpy()

#define fps 6

void obj_test(){
    u32 an = 1, run = 0;
    u32 x = 96, y = 32;
    u32 frame = 0, tid = 4;

    obj_set_attr(
        obj_buffer,
        ATTR0_SQUARE,
        ATTR1_SIZE_16x16,
        ATTR2_PRIO(4)
    );

    obj_set_pos(obj_buffer, x, y);

    while(1){
        VID_VSYNC;                          // set vsync
        KEY_POLL;                           // perform keypoll  // wow, that was easy
        
        run = KEY_IS_DOWN(KEY_B);

        x += KEY_TRI_HORZ<<run;
        y += KEY_TRI_VERT<<run;

        if(KEY_HIT(KEY_VERT)){
            an = 1;
            if(KEY_HIT(KEY_DOWN)){
                tid = 4;
            }else{
                tid = 0;
            }
        }if(KEY_HIT(KEY_HORZ)){
            tid = 8;
            an = 0;
            if(KEY_HIT(KEY_RIGHT)){
                obj_buffer->attr1 |= (ATTR1_HFLIP);
            }else{
                obj_buffer->attr1 &= (~ATTR1_HFLIP);
            }
        }

        if((!frame) && KEY_IS_DOWN(KEY_MOVE)){
            if(an){
                obj_buffer->attr1 ^= ATTR1_HFLIP;
            }else{
                tid ^= 4;
            }
        }

        obj_set_pos(obj_buffer, x, y);
        obj_buffer->attr2 = tid;

        oam_copy(oam_mem, obj_buffer, 1);
        frame = (frame+1)%(60/fps);
    }
}

int main(){
    memcpy(&tile_mem[4][0], sprite_test_4bpp_data, sprite_test_4bpp_size);          // put tile in the lowest mem
    memcpy(pal_obj_mem, sprite_test_4bpp_palette, sprite_test_4bpp_palette_size);   // put palette in palette mem

    oam_init(obj_buffer, 128);    // clear (init all sprite attributes) // just use 128 to clear em all
    REG_DISPCNT = DCNT_OBJ | DCNT_OBJ_1D;

    // run real test
    obj_test();

    return 0;
}
