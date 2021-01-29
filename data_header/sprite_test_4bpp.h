
/*
 * Image:        sprite_test_4bpp
 * Size:         512
 * Width:        16
 * Height:       64
 *
 * Palette size: 4
 */

#ifndef SPRITE_TEST_4BPP_H
#define SPRITE_TEST_4BPP_H

#define	sprite_test_4bpp_size 512	// Byte-expressed image size
#define	sprite_test_4bpp_length 128	// Array length
#define	sprite_test_4bpp_width 16	// Image Width
#define	sprite_test_4bpp_height 64	// Image Height
#define	sprite_test_4bpp_palette_size 8	// Bye-expressed Palette Size
#define	sprite_test_4bpp_palette_length 2	// Palette array length

extern const unsigned int sprite_test_4bpp_palette[sprite_test_4bpp_palette_length];
extern const unsigned int sprite_test_4bpp_data[sprite_test_4bpp_length];

#endif//SPRITE_TEST_4BPP_H