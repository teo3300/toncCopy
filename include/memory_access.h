#ifndef MEMORY_ACCESS_H
#define MEMORY_ACCESS_H

#include "memory_map.h"         // define how to access memory

#define vid_mem         MEM_MAP_16(MEM_VRAM)
#define pal_bg_mem      MEM_MAP_16(MEM_PAL)
#define pal_obj_mem     MEM_MAP_COLOR(MEM_PAL_OBJ)
#define tile_mem        MEM_MAP_CHARB(MEM_VRAM)
#define tile8_mem       MEM_MAP_CHARB8(MEM_VRAM)
#define oam_mem         MEM_MAP_OBJ_ATTR(MEM_OAM)

#endif // MEMORY_ACCESS_H
