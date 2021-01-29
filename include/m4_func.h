#ifndef M4_FUNC_H
#define  M4_FUNC_H

#include "mem_type.h"           // redefine data types
#include "registers_access.h"   // include all registers
#include "draw_functions.h"     // define all draw functions

#define M4_WIDTH 240        // pixel page width

u16 *vid_flip();
void m4_plot(int x, int y, u8 clrid);
void m4_fill(u8 clrid);

#endif // M4_FUNC_H
