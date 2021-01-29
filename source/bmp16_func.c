#include "bmp16_func.h"

void bmp16_line(int x1, int y1, int x2, int y2, u32 clr, void *dstBase, uint dstPitch){
    int ii, dx, dy, xstep, ystep, dd;
    u16 *dst= (u16*)(dstBase + y1*dstPitch + x1*2);
    dstPitch /= 2;

    // --- Normalization ---
    if(x1>x2)
    {   xstep= -1;  dx= x1-x2;  }
    else
    {   xstep= +1;  dx= x2-x1;  }

    if(y1>y2)
    {   ystep= -dstPitch;   dy= y1-y2;  }
    else
    {   ystep= +dstPitch;   dy= y2-y1;  }


    // --- Drawing ---

    if(dy == 0)         // Horizontal
    {
        for(ii=0; ii<=dx; ii++)
            *MEM_MAP_16(dst + ii*xstep)=clr;
            //dst[ii*xstep]= clr;
    }
    else if(dx == 0)    // Vertical
    {
        for(ii=0; ii<=dy; ii++)
            *MEM_MAP_16(dst + ii*ystep)=clr;
            //dst[ii*ystep]= clr;
    }
    else if(dx>=dy)     // Diagonal, slope <= 1
    {
        dd= 2*dy - dx;

        for(ii=0; ii<=dx; ii++)
        {
            *dst= clr;
            if(dd >= 0)
            {   dd -= 2*dx; dst += ystep;  }

            dd += 2*dy;
            dst += xstep;
        }
    }
    else                // Diagonal, slope > 1
    {
        dd= 2*dx - dy;

        for(ii=0; ii<=dy; ii++)
        {
            *dst= clr;
            if(dd >= 0)
            {   dd -= 2*dy; dst += xstep;  }

            dd += 2*dx;
            dst += ystep;
        }
    }
}

//! Draw a rectangle on a 16bpp canvas
void bmp16_rect(int left, int top, int right, int bottom, u32 clr, void *dstBase, uint dstPitch){
    int ix, iy;

    uint width= right-left, height= bottom-top;
    u16 *dst= (u16*)(dstBase+top*dstPitch + left*2);
    dstPitch /= 2;

    // --- Draw ---
    for(iy=0; iy<height; iy++)
        for(ix=0; ix<width; ix++)
            *MEM_MAP_16(dst + iy*dstPitch + ix)=clr;
            //dst[iy*dstPitch + ix]= clr;
}

//! Draw a frame on a 16bpp canvas
void bmp16_frame(int left, int top, int right, int bottom, u32 clr, void *dstBase, uint dstPitch){
    // Frame is RB exclusive
    right--;
    bottom--;

    bmp16_line(left,  top,   right,  top,    clr, dstBase, dstPitch);
    bmp16_line(left,  bottom, right, bottom, clr, dstBase, dstPitch);

    bmp16_line(left,  top,   left,   bottom, clr, dstBase, dstPitch);
    bmp16_line(right, top,   right,  bottom, clr, dstBase, dstPitch);
}

void bmp16_fill(COLOR clr, void *mBase, uint mSize){
    int ii;
    u32 *dst= MEM_MAP_32(mBase);
    u32 wd= (clr<<16) | clr;
    for(ii=0; ii<mSize>>1; ii++)
        *dst++= wd;
}
//
