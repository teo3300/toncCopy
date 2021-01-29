#ifndef BMP16_FUNC_H
#define  BMP16_FUNC_H

#include "mem_type.h"           // define data types
#include "memory_map.h"         // use mem map

#define bmp16_plot(x, y, clr, mBase, mWidth)   (*MEM_MAP_16(mBase + (y)*mWidth + (x)))=(clr)
void bmp16_line(int x1, int y1, int x2, int y2, u32 clr, void *dstBase, uint dstPitch);
void bmp16_rect(int left, int top, int right, int bottom, u32 clr, void *dstBase, uint dstPitch);
void bmp16_frame(int left, int top, int right, int bottom, u32 clr, void *dstBase, uint dstPitch);
void bmp16_fill(COLOR clr, void *mBase, uint mSize);

#endif // BMP16_FUNC_H
