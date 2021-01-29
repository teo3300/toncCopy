#ifndef GBA_MAIN_H
#define GBA_MAIN_H

#include "cntax.h"                  // define alternatives for syntax
#include "errors.h"                 // define error values
#include "mem_type.h"               // define variable types
#include "static_values.h"          // list static values for defined types or others (like screen size)
#include "colors.h"                 // list main colors and masks
#include "structures.h"             // define structures used // was before "draw_fungions.h"

#include "obj_attributes.h"         // contains definitions of object attribute values
#include "memory_access.h"          // define how to access memory sections
#include "registers_access.h"       // include all registers
#include "reg_functions.h"          // defined register functions

#include "draw_functions.h"         // includes all functions to draw on screen
#include "obj_func.h"               // functions to work with obj

// global setting definition
#define OBJ_BUFFER_SIZE     1       // I'm using 1 sprite only     

extern OBJ_ATTR obj_buffer[OBJ_BUFFER_SIZE];
extern OBJ_AFFINE* obj_aff_buffer;

// Include data files
#include "sprite_test_4bpp.h"

#endif // GBA_MAIN_H
