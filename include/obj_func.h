#ifndef OBJ_FUNC_H
#define OBJ_FUNC_H

#include "obj_attributes.h"
#include "mem_type.h"
#include "memory_map.h"
#include "memory_access.h"
#include "structures.h"

void oam_init(OBJ_ATTR *obj, uint count);
void oam_copy(OBJ_ATTR *dst, const OBJ_ATTR *src, uint count);

// set all attributes of object
#define obj_set_attr(obj, a0, a1, a2) \
{ \
    obj->attr0= a0; obj->attr1= a1; obj->attr2= a2;\
}

// use previous macros to set position
#define obj_set_pos(obj, x, y) \
{ \
    BF_SET(obj->attr0, y, ATTR0_Y); \
    BF_SET(obj->attr1, x, ATTR1_X); \
}

// hide an object
#define obj_hide(obj) \
{ \
    BF_SET2(obj->attr0, ATTR0_HIDE, ATTR0_MODE); \
}

// unhide (and set render method) for an objett
#define obj_unhide(obj, mode) \
{ \
    BF_SET2(obj->attr0, mode, ATTR0_MODE); \
}



// other macros (low level)
// building macros
#define ATTTR0_BUILD(y, shape, bpp, mode, mos, bld, win) \
    ( \
        ( (y)     & 255 )        | \
        (((mode)  & 3   ) << 8)  | \
        (((bld)   & 1   ) << 10) | \
        (((win)   & 1   ) << 11) | \
        (((mos)   & 1   ) << 12) | \
        (((bpp)   & 8   ) << 10) | \
        (((shape) & 3   ) << 14)   \
    )       // attr0 building    (I really hope devkitARM optimize all this shit)
            // YEP it does
            // Coranac, TFW did you use "& 8" and "<< 10" for bpp? do you hate 13 so much?
            // okok, so I can use 8 and 4 insteas of 1 and 0
#define ATTR1_BUILD_R(x, size, hflip, vflip) \
    ( \
        ( (x)     & 511 )        | \
        (((hflip) & 1   ) << 12) | \
        (((vflip) & 1   ) << 13) | \
        (((size)  & 3   ) << 14)   \
    )       // attr1 building normal render
#define ATTR1_BUILD_A(x, size, aff_id) \
    ( \
        ( (x)     & 511 )        | \
        (((aff_id)& 31  ) << 9 ) | \
        (((size)  & 3   ) << 14)   \
    )       // attr1 building affine render
#define ATTR2_BUILD(tid, pbank, prio) \
    ( \
        ( (tid)   & 1023)        | \
        (((prio)  & 3   ) << 10) | \
        (((pbank) & 15  ) << 12)   \
    )       // attr2 building
            // 1023 was initially 0x3FF

#endif // OBJ_FUNC_H