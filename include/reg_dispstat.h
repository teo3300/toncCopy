#ifndef REG_DISPSTAT_H
#define REG_DISPSTAT_H

// set if in VBlank
#define DSTAT_IN_VBL    0x0001  // Set VBlank, clear VDraw

// set in HBlank
#define DSTAT_IN_HBL    0x0002  // Set HBlank, clear HDraw

// set if current scanline match the trigger
#define DSTAT_IN_VCT    0x0004  // VCount trigger status REG_VCOUNT == REG_DISPSTAT{8-F}

// fire interrupt at VBlank
#define DSTAT_VBL_IRQ   0x0008  // VBlank interrupt request

// fire interrupt at HBlank
#define DSTAT_HBL_IRQ   0x0010  // HBlank interrupt request

// fire interrupt if current scanline match trigger
#define DSTAT_VCT_IRQ   0x0020  // VCount interrupt request

// set scanline trigger value
#define DSTAT_VCT_MSAK  0xFF00  // Vcount trigger mask
#define DSTAT_VCT_SHIFT 8       // VCount shift position
#define DSTAT_VCT(n) ((n)<<DSTAT_VCT_SHIFT)


#endif // REG_DISPSTAT_H
