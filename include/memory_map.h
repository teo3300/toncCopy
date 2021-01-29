#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H
//main sectors
#define MEM_EWRAM       0x02000000
#define MEM_IWRAM       0x03000000
#define MEM_IO          0x04000000
#define MEM_PAL         0x05000000
#define MEM_VRAM        0x06000000
#define MEM_OAM         0x07000000
#define MEM_ROM         0x08000000
#define MEM_SRAM        0x0e000000
//sectors size

#define EWRAM_SIZE      0x00040000
#define IWRAM_SIZE      0x00008000
#define PAL_SIZE        0x00000400
#define VRAM_SIZE       0x00018000
#define OAM_SIZE        0x00000400
#define SRAM_SIZE       0x00010000
//sub section size

#define PAL_BG_SIZE     0x00000200
#define PAL_OBJ_SIZE    0x00000200

#define VRAM_PAGE_SIZE  0x0000a000
#define VID_FLIP        VRAM_PAGE_SIZE
//sub sections

#define REG_BASE        MEM_IO
#define MEM_PAL_BG      MEM_PAL
#define MEM_PAL_OBJ    (MEM_PAL+PAL_BG_SIZE)
#define MEM_VRAM_FRONT  MEM_VRAM
#define MEM_VRAM_BACK  (MEM_VRAM+VRAM_PAGE_SIZE)

#define MEM_MAP_16(index)       ((u16*)         (index))    // allow access as u16 array
#define MEM_MAP_32(index)       ((u32*)         (index))    // allow access as u32 array
#define MEM_MAP_COLOR(index)    ((COLOR*)       (index))    // allow access as COLOR (u16) array
#define MEM_MAP_CHARB(index)    ((CHARBLOCK*)   (index))    // addresses VRAM as a matrix of chars single size
#define MEM_MAP_CHARB8(index)   ((CHARBLOCK8*)  (index))    // addresses VRAM as a matrix of chars souble size
#define MEM_MAP_OBJ_ATTR(index) ((OBJ_ATTR*)    (index))    // addresses OAM with OA size (4*16 bit) (?)

#define REG_MAP_16(index)      *((vu16*)        (index))    // allow access to u16 registers
#define REG_MAP_32(index)      *((vu32*)        (index))    // allow access to u16 registers

#endif // MEMORY_MAP_H
