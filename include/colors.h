#ifndef COLORS_H
#define COLORS_H

#define 	CLR_BLACK       0x0000
#define 	CLR_RED         0x001F
#define 	CLR_LIME        0x03E0
#define 	CLR_YELLOW      0x03FF
#define 	CLR_BLUE        0x7C00
#define 	CLR_MAG         0x7C1F
#define 	CLR_CYAN        0x7FE0
#define 	CLR_WHITE       0x7FFF
#define 	CLR_DEAD        0xDEAD
#define 	CLR_MAROON      0x0010
#define 	CLR_GREEN       0x0200
#define 	CLR_OLIVE       0x0210
#define 	CLR_ORANGE      0x021F
#define 	CLR_NAVY        0x4000
#define 	CLR_PURPLE      0x4010
#define 	CLR_TEAL        0x4200
#define 	CLR_GRAY        0x4210
#define 	CLR_MEDGRAY     0x5294
#define 	CLR_SILVER      0x6318
#define 	CLR_MONEYGREEN  0x6378
#define 	CLR_FUCHSIA     0x7C1F
#define 	CLR_SKYBLUE     0x7B34
#define 	CLR_CREAM       0x7BFF

#define     CLR_MASK        0x001f
#define     RED_MASK        0x001f
#define     RED_SHIFT       0
#define     GREEN_MASK      0x03e0
#define     GREEN_SHIFT     5
#define     BLUE_MASK       0x7c00
#define     BLUE_SHIFT      10

#define RGB15(r,g,b)        ( (r)            | ((g)            <<GREEN_SHIFT)| ((b)            <<BLUE_SHIFT))
#define RGB15_SAFE(r,g,b)   (((r) & CLR_MASK)|(((g) & CLR_MASK)<<GREEN_SHIFT)|(((b) & CLR_MASK)<<BLUE_SHIFT))
#define CLAMP(x, min, max)  ( (x)>=(max) ? ((max)-1) : ( ((x)<(min)) ? (min) : (x) ) )

#endif // COLORS_H
