#ifndef OBJ_ATTRIBUTES_H
#define OBJ_ATTRIBUTES_H

#include "structures.h"

// attribute 0 values
// defines sprite attribs Y coords, shape, transformable, bitdepth

// vertical position (top)
#define ATTR0_Y_MASK        0x00FF          // sprite position on screen
#define ATTR0_Y_SHIFT       0
#define ATTR0_Y(n)          ((n)<<ATTR0_Y_SHIFT)

// affine object mode
#define ATTR0_REG           0x0000          // normal rendering (disable affine)
#define ATTR0_AFF           0x0100          // use affine matrix
#define ATTR0_HIDE          0x0200          // disable rendering (hides)
#define ATTR0_AFF_DBL       0x0300          // use affine matrix using double area

#define ATTR0_MODE_MASK     0x0300
#define ATTR0_MODE_SHIFT    8
#define ARRT0_MODE(n)       ((n)<<ATTR0_MODE_SHIFT)

// special effects
#define ATTR0_BLEND         0x0400
#define ATTR0_WIN           0x0800

#define ATTR0_GFX_MASK      0x0C00
#define ATTR0_GFX_SHIFT     10
#define ATTR0_GFX(n)        ((n)<<ATTR0_GFX_SHIFT)

// mosaic effect
#define ATTR0_MOSAIC_NONE   0x0000          // disable mosaic effect
#define ATTR0_MOSAIC        0x1000          // enable mosaic effect

#define ATTR0_MOSAIC_MASK   0x1000

// bitdepth
#define ATTR0_4BPP          0x0000          // specify 4bpp
#define ATTR0_8BPP          0x2000          // specify 8bpp

#define ATTR0_BPP_MASK      0x2000

// sprite shape
#define ATTR0_SQUARE        0x0000          // sprite is a square (see attr1{E-F})
#define ATTR0_WIDE          0x4000          // sprite is a wide rectangle // defined teble at the and
#define ATTR0_TALL          0x8000          // sprite is a tall rectangle //

#define ATTR0_SHAPE_MASK    0xC000
#define ATTR0_SHAPE_SHIFT   14
#define ATTR0_SHAPE(n)      ((n)<<ATTR0_SHAPE_SHIFT)

// attr1 values
// defines sprite attribs X coord, size, affinity transform, flipping

// horizontal position (left)
#define ATTR1_X_MASK        0X01FF          // sprite position on screen
#define ATTR1_X_SHIFT       0
#define ATTR1_X(n)          ((n)<<ATTR1_X_SHIFT)

// Affine InDex
#define ATTR1_AFF_MASK      0x3E00
#define ATTR1_AFF_SHIFT     9
#define ATTR1_AFF(n)        ((n)<<ATTR1_AFF_SHIFT)

// horizontal and verticall flipping only if affine flag is 0
#define ATTR1_HFLIP         0x1000          // fllip vertically
#define ATTR1_VFLIP         0x2000          // horizontal flip

#define ATTR1_FLIP_MASK     0x3000

// sprite size (see attr0{E-F})
#define ATTR1_SIZE_MASK     0xC000
#define ATTR1_SIZE_SHIFT    14
#define ATTR1_SIZE(n)       ((n)<<ATTR1_SIZE_SHIFT)

#define ATTR1_SIZE_8x8      ATTR1_SIZE(0)
#define ATTR1_SIZE_16x8     ATTR1_SIZE(0)
#define ATTR1_SIZE_8x16     ATTR1_SIZE(0)

#define ATTR1_SIZE_16x16    ATTR1_SIZE(1)
#define ATTR1_SIZE_32x8     ATTR1_SIZE(1)
#define ATTR1_SIZE_8x32     ATTR1_SIZE(1)

#define ATTR1_SIZE_32x32    ATTR1_SIZE(2)
#define ATTR1_SIZE_32x16    ATTR1_SIZE(2)
#define ATTR1_SIZE_16x32    ATTR1_SIZE(2)

#define ATTR1_SIZE_64x64    ATTR1_SIZE(3)
#define ATTR1_SIZE_64x32    ATTR1_SIZE(3)
#define ATTR1_SIZE_32x64    ATTR1_SIZE(3)


// attr2 values
// defines sprite attribs base tile index, priority (layer), palette bank

// basetile ID
#define ATTR2_ID_MASK       0x03FF
#define ATTR2_ID_SHIFT      10
#define ATTR2_ID(n)         ((n)<<ATTR2_ID_SHIFT)

// draw priority (lower first)
#define ATTR2_PRIO_MASK     0x0C00
#define ATTR2_PRIO_SHIFT    10
#define ATTR2_PRIO(n)       ((n)<<ATTR2_PRIO_SHIFT)

// palette bank
#define ATTR2_PALBANK_MASK  0xF000
#define ATTR2_PALBANK_SHIFT 12
#define ATTR2_PALBANK(n)    ((n)<<ATTR2_PALBANK_SHIFT)

// macro for bitfield handling
// and struct initialization

// shift-number version
#define BF_PREP(x,   name)  ( ((x) << name##_SHIFT) & name##_MASK )         // prepare bitfield for use
#define BF_GET(x,    name)  ( ((x) & name##_MASK) >> name##_SHIFT )         // get bitfield
#define BF_SET(y, x, name)  ( y = ((y) & ~name##_MASK) | BF_PREP(x, name))  // set bitfield

// plain name version
#define BF_PREP2(x,   name) ( (x) & name##_MASK )                           // prepare bitfield for use
#define BF_GET2(x,    name) ( (x) & name##_MASK )                           // get bitfield
#define BF_SET2(y, x, name) ( y = ((y) & ~name##_MASK) | BF_PREP2(x, name)) // set bitfield

#endif // OBJ_ATTRIBUTES_H