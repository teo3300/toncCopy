#ifndef REGISTER_ACCESS_H
#define REGISTER_ACCESS_H

#define  REG_DISPCNT  REG_MAP_32(MEM_IO)         // I/O DISPLAY_CONTROL
#include "reg_dispcnt.h"                         // controls mode, layers, Background, objects

#define  REG_DISPSTAT REG_MAP_16(MEM_IO+0x0004)  // REG_MAP_16(MEM_IO+0x0004)  // I/O DISPLAY_STATUS
#include "reg_dispstat.h"                        // provide infos about display snd set interrupts for video rendering

#define  REG_VCOUNT   REG_MAP_16(MEM_IO+0x0006)  // I/O DISPLAY_VCOUNT
#include "reg_vcount.h"                          // provide current rendering scanline

#define  REG_KEYS     REG_MAP_16(MEM_IO+0x0130)  // KEYS_input_REGISTER
#include "reg_keys.h"                            // provide input masks

#define  REG_KEYCNT   REG_MAP_!&(MEM_IO+0x0132)  // KEYS_intput_CONTROL_REGISTER
#include "reg_keycnt.h"                          // manage interrupts

#endif // REGISTER_ACCESS_H
