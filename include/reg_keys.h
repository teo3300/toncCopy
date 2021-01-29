#ifndef REG_KEYS_H
#define REG_KEYS_H

//  glbal definition in GBA_main.c
extern u16 __key_curr, __key_prev;

// Button names
#define KEY_A       0x0001
#define KEY_B       0x0002
#define KEY_FIRE    KEY_A | KEY_B

#define KEY_SELECT  0x0004
#define KEY_START   0x0008
#define KEY_MENU    KEY_SELECT | KEY_START

#define KEY_RIGHT   0x0010
#define KEY_LEFT    0x0020
#define KEY_UP      0x0040
#define KEY_DOWN    0x0080
#define KEY_HORZ    KEY_RIGHT | KEY_LEFT
#define KEY_VERT    KEY_UP | KEY_DOWN
#define KEY_MOVE    KEY_HORZ | KEY_VERT

#define KEY_R       0x0100
#define KEY_L       0x0200
#define KEY_SHLD    KEY_R | KEY_L 

#define KEY_ALL     0xffffffff
// Button mask
#define KEY_MASK    0x03ff

//  Key is down (meh)
#define KEY_DOWN_NOW(key)   (~(REG_KEYS) & (key)) // Check if the key is pressed (almost never used)
// bits are cleared when a key is pressed
// To call at every frame (poll keys)

#define KEY_POLL \
  { \
    __key_prev = __key_curr; \
    __key_curr = ~REG_KEYS & KEY_MASK; \
  }                                                // Assign curr to prev (keep track of keys) // read input

// Function to check key status (after key poll)
#define KEY_CURR_STATE      (  __key_curr)           // Return current state
#define KEY_PREV_STATE      (  __key_prev)           // Return previous state
#define KEY_IS_DOWN(key)    (  __key_curr & (key))   // key (or) key-combo is down
#define KEY_IS_UP(key)      ( ~__key_curr & (key))   // key (or) key-combo is up
#define KEY_WAS_DOWN(key)   (  __key_prev & (key))   // key (or) key-combo was down // previous fame
#define KEY_WAS_UP(key)     ( ~__key_prev & (key))   // key (or) key-combo was up   //

// Use both "curr" and "prev" to check state changes (UD/DU, DD, UD, DU)
#define KEY_TRANSIT(key)    ((( __key_curr ^  __key_prev) & (key)))  // Specified key transit (UD, DU)
#define KEY_HELD(key)       ((( __key_curr &  __key_prev) & (key)))  // Specified key held
#define KEY_HIT(key)        ((( __key_curr &~ __key_prev) & (key)))  // Specified key pressed
#define KEY_RELEASED(key)   (((~__key_curr &  __key_prev) & (key)))  // Specified key released


/** From this point handle tribool **/

enum eKeyIndex{
  KI_A=0, KI_B, KI_SELECT, KI_START,      // I'll keep it like this
  KI_RIGHT, KI_LEFT, KI_UP, KI_DOWN,
  KI_R, KI_L, KI_MAX
};

// plus | minus || result
//  0   |   0   ||   0
//  1   |   0   ||   1
//  0   |   1   ||  -1
//  1   |   1   ||   0

#define BIT_TRIBOOL(x, plus, minus)     (((x >>plus) & 1) - ((x >> minus) & 1))

#define KEY_TRI_HORZ      BIT_TRIBOOL(__key_curr, KI_RIGHT, KI_LEFT)
#define KEY_TRI_VERT      BIT_TRIBOOL(__key_curr, KI_DOWN,  KI_UP  )
#define KEY_TRI_SHOULDER  BIT_TRIBOOL(__key_curr, KI_R,     KI_L   )
#define KEY_TRI_FIRE      BIT_TRIBOOL(__key_curr, KI_A,     KI_B   )

#endif // REG_KEYS
