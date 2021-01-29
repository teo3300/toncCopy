#include "GBA_main.h"

u16 __key_curr, __key_prev;                                     // track gamepad state

OBJ_ATTR     obj_buffer[OBJ_BUFFER_SIZE];                        // buffer for obj_attr
OBJ_AFFINE  *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;           // same pointer for obj_affine

/**Place here all global variables and struct for game**/
