#ifndef REG_DISPCNT_H
#define REG_DISPCNT_H

// display control mode
#define DCNT_MODE0          0x0000  //Tiled
#define DCNT_MODE1          0x0001  //
#define DCNT_MODE2          0x0002  //
#define DCNT_MODE3          0x0003  //Bitmap
#define DCNT_MODE4          0x0004  //
#define DCNT_MODE5          0x0005  //

#define DCNT_MODE_MASK      0x0007
#define DCNT_MODE_SHIFT     0
#define DCNT_MODE(n)        ((n)<<DCNT_MODE_SHIFT)

// GB flag
#define DCNT_GB             0x0008  //Set if cartridge is GBC

// used for page flipping
#define DCNT_PAGE           0x0010  //mode 4-5 page flipping

// allow access to OAMin HBlank (normally locked)
#define DCNT_OAM_HBL        0x0020  //allows OAM access in HBlank

// object mapping as 1D array
#define DCNT_OBJ_1D         0x0040  //Arrange tiles as 1D array

// force blank screen
#define DCNT_BLANK          0x0080  //Force blank screen

// enable layer rendering
#define DCNT_BG0            0x0100  //Enable rendering of the BG0
#define DCNT_BG1            0x0200  //Enable rendering of the BG1
#define DCNT_BG2            0x0400  //Enable rendering of the BG2
#define DCNT_BG3            0x0800  //Enable rendering of the BG3
#define DCNT_OBJ            0x1000  //Enable rendering of objects

#define DCNT_LAYER_MASK     0x1F00
#define DCNT_LAYER_SHIFT    8
#define DCNT_LAYER(n)       ((n)<<DCNT_LAYER_SHIFT)

// enable use of windows
#define DCNT_WIN0           0x2000  //Enables windows 0,1,Obj
#define DCNT_WIN1           0x4000  //
#define DCNT_WINOBJ         0x8000  //

#endif // REG_DISPCNT_H
