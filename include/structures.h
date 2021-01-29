#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "mem_type.h"                           // to allow memtype macros

// Tyles struct definitions
typedef struct {u32 data[8];} TILE, TILE4;      // 8*8@4bpp = 64/2 = 32 byte

typedef struct {u32 data[16];} TILE8;           // 8*8@8bpp = 64 byte

typedef TILE CHARBLOCK[512];                    // define charblock as an array of tiles
typedef TILE8 CHARBLOCK8[256];                  //or an array of double tiles

typedef struct OBJ_ATTR                         // object attribute struct
{
    u16 attr0;
    u16 attr1;
    u16 attr2;
    s16 fill;
} ALIGN(4) OBJ_ATTR;

typedef struct OBJ_AFFINE                       // object affinity struct
{
    u16 fill0[3];
    s16 pa;
    u16 fill1[3];
    s16 pb;
    u16 fill2[3];
    s16 pc;
    u16 fill3[3];
    s16 pd;
} ALIGN(4) OBJ_AFFINE;

#endif // STRUCTURES_H

