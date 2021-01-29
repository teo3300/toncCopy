#ifndef M3_FUNC_H
#define  M3_FUNC_H

#define M3_SIZE         0x12C00
#define M3_WIDTH        240
#define DOUBLE_M3_WIDTH 480

#define m3_plot(x, y, clr)                      bmp16_plot (x,      y,                clr, vid_mem, M3_WIDTH)
#define m3_line(x1, y1, x2, y2, clr)            bmp16_line ( x1,   y1,    x2,     y2, clr, vid_mem, DOUBLE_M3_WIDTH)
#define m3_rect(left, top, right, bottom, clr)  bmp16_rect (left, top, right, bottom, clr, vid_mem, DOUBLE_M3_WIDTH)
#define m3_frame(left, top, right, bottom, clr) bmp16_frame(left, top, right, bottom, clr, vid_mem, DOUBLE_M3_WIDTH)
#define m3_fill(clr)                            bmp16_fill (clr, vid_mem, M3_SIZE)

#endif // M3_FUNC_H
