#include "obj_func.h"

// oam_init and oam_copy are a copy-paste from tonc

void oam_init(OBJ_ATTR *obj, uint count){
    u32 nn= count;          // sizeof(OBJ_ATTR) = 2 sizeof(u32) 
    u32 *dst= (u32*)obj;    // 

    // Hide all objects and set everything else to 0 
    while (nn--) {
        *dst++ = ATTR0_HIDE;
        *dst++ = 0;
    }

    // init oam (copy all cleared elements to oam_mem)
    oam_copy(oam_mem, obj, count);
}

void oam_copy(OBJ_ATTR *dst, const OBJ_ATTR *src, uint count){
  
    // directly from tonc, to avod problem in compiling
    // use word-copy instead of struct-copy
    #if 0
        while (count--)
            *dst++ = *src++;
    #else
        // convert from struct to u32, then copy
        u32 *dstw= (u32*)dst, *srcw= (u32*)src;
        while(count--){
            *dstw++ = *srcw++;
            *dstw++ = *srcw++;
        }
    #endif
}