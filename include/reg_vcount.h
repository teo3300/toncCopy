#ifndef REG_VCOUNT_H
#define REG_VCOUNT_H


#define VID_VSYNC \
    { \
        while(REG_DISPSTAT & DSTAT_IN_VBL);  \
        while(~REG_DISPSTAT & DSTAT_IN_VBL); \
    }                                               // Faster (?)
// ^ loops while inside VBlank
#define SLOW_VID_VSYNC    \
    { \
        while(REG_VCOUNT>=160); \
        while(REG_VCOUNT <160); \
    }                                               // Slower (?)
#endif // REG_VCOUNT_H
