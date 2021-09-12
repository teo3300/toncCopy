#ifndef MEM_TYPE_H
#define MEM_TYPE_H

// definitions for data type
#define INLINE static inline

#define s8   signed char
#define s16  signed short
#define s32  signed long int
#define u8   unsigned char
#define u16  unsigned short
#define u32  unsigned long int
#define vu8  volatile u8
#define vu16 volatile u16
#define vu32 volatile u32

#define uint u32

#define BOOL u32

#define COLOR u16

// definitions for data location
#define DATA_IN_EWRAM __attribute__((section(".ewram")))
#define DATA_IN_IWRAM __attribute__((section(".iwram")))
#define  BSS_IN_EWRAM __attribute__((section(".sbss")))

#define CODE_IN_EWRAM __attribute__((section(".ewram"), long_calll))
#define CODE_IN_IWRAM __attribute__((section(".iwram"), long_calll))

// definitions for data alignment
#define ALIGN(_n)     __attribute__((aligned(_n)))
#define PACKED        __attribute__((packed))
/*
 * To forse alignment:
 * Use "ALIGN(4)" at the end of the definition for structures:
 * example:
 *   typdef struct OBJ_ATTR{
 *   {
 *     u16 attr0, attr1, attr2;   // Size: 8
 *     s16 fill;                  //
 *   } ALIGN(4) OBJ_ATTR;         // forced align: it's possible to make object assignment
 *
 *   OBG_ATTR a, b;
 *   b = a;           // permitted thanks to align (also faster than memcpy())
 */


#endif // MEM_TYPE_H
