/*
Arduino ScoreBoard - By Joao Xavier
Version 0 - 12 sep 2016
*/

#include "VGAX.h"
#include "VGAXUtils.h"
#define FNT_NANOFONT_HEIGHT 6
#define FNT_NANOFONT_SYMBOLS_COUNT 94



//#define blueButton 22
//#define redButton 23


VGAX vga;
VGAXUtils vgaU;


#define IMG_VARNAME_BWIDTH 30
#define IMG_VARNAME_HEIGHT 60
//data size=900 bytes
const unsigned char img_varname_data[IMG_VARNAME_HEIGHT * IMG_VARNAME_BWIDTH] PROGMEM = {
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,
	170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 170, 85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,  85,


};

//data size=570 bytes
const unsigned char fnt_nanofont_data[FNT_NANOFONT_SYMBOLS_COUNT][1 + FNT_NANOFONT_HEIGHT] PROGMEM = {
	{ 1, 128, 128, 128, 0, 128, 0, }, //glyph '!' code=0
	{ 3, 160, 160, 0, 0, 0, 0, }, //glyph '"' code=1
	//{ 5, 80, 248, 80, 248, 80, 0, },  //glyph '#' code=2-
	{ 5, 248, 248, 248, 248, 248, 0, },  //glyph '#' code=2 - full rectangle
	{ 5, 120, 160, 112, 40, 240, 0, },  //glyph '$' code=3
	{ 5, 136, 16, 32, 64, 136, 0, },  //glyph '%' code=4
	{ 5, 96, 144, 104, 144, 104, 0, },  //glyph '&' code=5
	{ 2, 128, 64, 0, 0, 0, 0, },  //glyph ''' code=6
	{ 2, 64, 128, 128, 128, 64, 0, }, //glyph '(' code=7
	{ 2, 128, 64, 64, 64, 128, 0, },  //glyph ')' code=8
	{ 3, 0, 160, 64, 160, 0, 0, },  //glyph '*' code=9
	{ 3, 0, 64, 224, 64, 0, 0, }, //glyph '+' code=10
	{ 2, 0, 0, 0, 0, 128, 64, },  //glyph ',' code=11
	{ 3, 0, 0, 224, 0, 0, 0, }, //glyph '-' code=12
	{ 1, 0, 0, 0, 0, 128, 0, }, //glyph '.' code=13
	{ 5, 8, 16, 32, 64, 128, 0, },  //glyph '/' code=14
	{ 4, 96, 144, 144, 144, 96, 0, }, //glyph '0' code=15
	{ 3, 64, 192, 64, 64, 224, 0, },  //glyph '1' code=16
	{ 4, 224, 16, 96, 128, 240, 0, }, //glyph '2' code=17
	{ 4, 224, 16, 96, 16, 224, 0, },  //glyph '3' code=18
	{ 4, 144, 144, 240, 16, 16, 0, }, //glyph '4' code=19
	{ 4, 240, 128, 224, 16, 224, 0, },  //glyph '5' code=20
	{ 4, 96, 128, 224, 144, 96, 0, }, //glyph '6' code=21
	{ 4, 240, 16, 32, 64, 64, 0, }, //glyph '7' code=22
	{ 4, 96, 144, 96, 144, 96, 0, },  //glyph '8' code=23
	{ 4, 96, 144, 112, 16, 96, 0, },  //glyph '9' code=24
	{ 1, 0, 128, 0, 128, 0, 0, }, //glyph ':' code=25
	{ 2, 0, 128, 0, 0, 128, 64, },  //glyph ';' code=26
	{ 3, 32, 64, 128, 64, 32, 0, }, //glyph '<' code=27
	{ 3, 0, 224, 0, 224, 0, 0, }, //glyph '=' code=28
	{ 3, 128, 64, 32, 64, 128, 0, },  //glyph '>' code=29
	{ 4, 224, 16, 96, 0, 64, 0, },  //glyph '?' code=30
	{ 4, 96, 144, 176, 128, 112, 0, },  //glyph '@' code=31
	{ 4, 96, 144, 240, 144, 144, 0, },  //glyph 'A' code=32
	{ 4, 224, 144, 224, 144, 224, 0, }, //glyph 'B' code=33
	{ 4, 112, 128, 128, 128, 112, 0, }, //glyph 'C' code=34
	{ 4, 224, 144, 144, 144, 224, 0, }, //glyph 'D' code=35
	{ 4, 240, 128, 224, 128, 240, 0, }, //glyph 'E' code=36
	{ 4, 240, 128, 224, 128, 128, 0, }, //glyph 'F' code=37
	{ 4, 112, 128, 176, 144, 112, 0, }, //glyph 'G' code=38
	{ 4, 144, 144, 240, 144, 144, 0, }, //glyph 'H' code=39
	{ 3, 224, 64, 64, 64, 224, 0, },  //glyph 'I' code=40
	{ 4, 240, 16, 16, 144, 96, 0, },  //glyph 'J' code=41
	{ 4, 144, 160, 192, 160, 144, 0, }, //glyph 'K' code=42
	{ 4, 128, 128, 128, 128, 240, 0, }, //glyph 'L' code=43
	{ 5, 136, 216, 168, 136, 136, 0, }, //glyph 'M' code=44
	{ 4, 144, 208, 176, 144, 144, 0, }, //glyph 'N' code=45
	{ 4, 96, 144, 144, 144, 96, 0, }, //glyph 'O' code=46
	{ 4, 224, 144, 224, 128, 128, 0, }, //glyph 'P' code=47
	{ 4, 96, 144, 144, 144, 96, 16, },  //glyph 'Q' code=48
	{ 4, 224, 144, 224, 160, 144, 0, }, //glyph 'R' code=49
	{ 4, 112, 128, 96, 16, 224, 0, }, //glyph 'S' code=50
	{ 3, 224, 64, 64, 64, 64, 0, }, //glyph 'T' code=51
	{ 4, 144, 144, 144, 144, 96, 0, },  //glyph 'U' code=52
	{ 3, 160, 160, 160, 160, 64, 0, },  //glyph 'V' code=53
	{ 5, 136, 168, 168, 168, 80, 0, },  //glyph 'W' code=54
	{ 4, 144, 144, 96, 144, 144, 0, },  //glyph 'X' code=55
	{ 3, 160, 160, 64, 64, 64, 0, },  //glyph 'Y' code=56
	{ 4, 240, 16, 96, 128, 240, 0, }, //glyph 'Z' code=57
	{ 2, 192, 128, 128, 128, 192, 0, }, //glyph '[' code=58
	{ 5, 128, 64, 32, 16, 8, 0, },  //glyph '\' code=59
	{ 2, 192, 64, 64, 64, 192, 0, },  //glyph ']' code=60
	{ 5, 32, 80, 136, 0, 0, 0, }, //glyph '^' code=61
	{ 4, 0, 0, 0, 0, 240, 0, }, //glyph '_' code=62
	{ 2, 128, 64, 0, 0, 0, 0, },  //glyph '`' code=63
	{ 3, 0, 224, 32, 224, 224, 0, },  //glyph 'a' code=64
	{ 3, 128, 224, 160, 160, 224, 0, }, //glyph 'b' code=65
	{ 3, 0, 224, 128, 128, 224, 0, }, //glyph 'c' code=66
	{ 3, 32, 224, 160, 160, 224, 0, },  //glyph 'd' code=67
	{ 3, 0, 224, 224, 128, 224, 0, }, //glyph 'e' code=68
	{ 2, 64, 128, 192, 128, 128, 0, },  //glyph 'f' code=69
	{ 3, 0, 224, 160, 224, 32, 224, },  //glyph 'g' code=70
	{ 3, 128, 224, 160, 160, 160, 0, }, //glyph 'h' code=71
	{ 1, 128, 0, 128, 128, 128, 0, }, //glyph 'i' code=72
	{ 2, 0, 192, 64, 64, 64, 128, },  //glyph 'j' code=73
	{ 3, 128, 160, 192, 160, 160, 0, }, //glyph 'k' code=74
	{ 1, 128, 128, 128, 128, 128, 0, }, //glyph 'l' code=75
	{ 5, 0, 248, 168, 168, 168, 0, }, //glyph 'm' code=76
	{ 3, 0, 224, 160, 160, 160, 0, }, //glyph 'n' code=77
	{ 3, 0, 224, 160, 160, 224, 0, }, //glyph 'o' code=78
	{ 3, 0, 224, 160, 160, 224, 128, }, //glyph 'p' code=79
	{ 3, 0, 224, 160, 160, 224, 32, },  //glyph 'q' code=80
	{ 3, 0, 224, 128, 128, 128, 0, }, //glyph 'r' code=81
	{ 2, 0, 192, 128, 64, 192, 0, },  //glyph 's' code=82
	{ 3, 64, 224, 64, 64, 64, 0, }, //glyph 't' code=83
	{ 3, 0, 160, 160, 160, 224, 0, }, //glyph 'u' code=84
	{ 3, 0, 160, 160, 160, 64, 0, },  //glyph 'v' code=85
	{ 5, 0, 168, 168, 168, 80, 0, },  //glyph 'w' code=86
	{ 3, 0, 160, 64, 160, 160, 0, },  //glyph 'x' code=87
	{ 3, 0, 160, 160, 224, 32, 224, },  //glyph 'y' code=88
	{ 2, 0, 192, 64, 128, 192, 0, },  //glyph 'z' code=89
	{ 3, 96, 64, 192, 64, 96, 0, }, //glyph '{' code=90
	{ 1, 128, 128, 128, 128, 128, 0, }, //glyph '|' code=91
	{ 3, 192, 64, 96, 64, 192, 0, },  //glyph '}' code=92
	{ 3, 96, 192, 0, 0, 0, 0, },  //glyph '~' code=93
};

//text statics for output vga
static const char str31[] PROGMEM = "Score";
static const char str32[] PROGMEM = "Set";
static const char str33[] PROGMEM = "Match";
static const char str34[] PROGMEM = "Select Service";
static const char str35[] PROGMEM = "Select Sets";
static const char str36[] PROGMEM = "Select Points";
/* in portugese
//text statics for output vga
static const char str31[] PROGMEM = "Pontos";
static const char str32[] PROGMEM = "Set";
static const char str33[] PROGMEM = "Partida";
static const char str34[] PROGMEM = "Selecione saque";
static const char str35[] PROGMEM = "Selecione Sets";
static const char str36[] PROGMEM = "Selecione Pontos";
*/
//create variable of control points
int blueScore = 0;
int redScore = 0;
int blueSet = 0;
int redSet = 0;
int blueMatch = 0;
int redMatch = 0;

boolean service = 0; //if 0 = red
boolean initialService = service;
boolean initialMatchService = service;

//set number of points and sets in game
int numSets = 3;
int numPoints = 11;

//name of players
char *playerRed="";
char *playerBlue="";


//control screen of game, change here, and in reset function
int stategame = 2;

boolean tmpBlue=0;
boolean tmpRed=0;

//control debounce
long lastDebounceTime = 0;
int debounceDelay = 50;

char* custom_itoa(int i)
{
    static char output[3]; 
    char* p = &output[2];
    if(i==0){
      return "0";}
    for(*p--=0;i;i/=10) *p--=i%10+0x30; 
    return ++p;    
}

//read button with debouce witchout delay
boolean readButtonRed() {

	tmpRed = (PINA & (1 << PINA1));


	if ( (vga.millis() - lastDebounceTime) > debounceDelay) {

		if (tmpRed != 0) {
			lastDebounceTime = vga.millis();
			drawBaseScreen();
			return 1;

		} else return 0;



	} else return 0;

}


//read button with debouce witchout delay
boolean readButtonBlue() {
	tmpBlue = (PINA & (1 << PINA0));


	if ( (vga.millis() - lastDebounceTime) > debounceDelay) {

		if (tmpBlue != 0) {
			lastDebounceTime = vga.millis();
			drawBaseScreen();
			return 1;

		} else return 0;



	} else return 0;


}

boolean readTwoButtons() {
	if ((PINA & (1 << PINA0)) != 0 && (PINA & (1 << PINA1)) != 0) {
		return 1;
	} else return 0;
}


boolean anzBlue=0;
boolean anzRed=0;
boolean anzTwo=0;

void analyzeButton() {
	anzBlue = readButtonBlue();
	anzRed = readButtonRed();
	anzTwo = readTwoButtons();
	if (stategame == 0) {
  
		if (anzBlue != 0) {
			numPoints = 15;
			stategame++;
		} else if (anzRed == 1) {
			numPoints = 11;
			stategame++;
		}
	}
	else if (stategame == 1) {
		if (anzBlue == 1) {
			numSets = 5;
			stategame++;
		} else if (anzRed == 1) {
			numSets = 3;
			stategame++;
		}
	}
	else if (stategame == 2) {
		
		if (anzBlue != 0) {
			service = 1;
			initialService = 1;
			initialMatchService = 1;
			stategame++;

		} else if (anzRed != 0) {
			service = 0;
			initialService = 0;
			initialMatchService = 0;
			stategame++;

		}
	}
	else if (stategame == 3) {

		if (anzTwo != 0) {
			reset();
		}

		else if (anzBlue != 0) {
			blueScore++;
			changeService();
			finalSet();
			finalMatch();

		} else if (anzRed != 0) {
			redScore++;
			changeService();
			finalSet();
			finalMatch();
		}
	}
}

//reset variables
void reset() {
	//return first srcreen
	blueScore = 0;
	redScore = 0;
	blueSet = 0;
	redSet = 0;
	blueMatch = 0;
	redMatch = 0;

	service = 0; //if 0 = red


	numSets = 3;
	numPoints = 11;

	stategame = 2;
  drawBaseScreen();
}
/*
################ rules of game ###########################
*/

void changeService() {
	if(redScore>=10&&blueScore>=10){
		service=!service;
	}else if ((redScore + blueScore) % 2 == 0) {
		service = !service;
	}
}
void finalSet() {
    
	if (blueScore >= 7 && redScore == 0) {
		blueSet++;
		blueScore = 0;
		redScore = 0;
		service = !initialService;
		initialService = service;
	}
	else if (redScore >= 7 && blueScore == 0) {
		redSet++;
		blueScore = 0;
		redScore = 0;
		service = !initialService;
		initialService = service;
	}
	else if ((blueScore >= numPoints) && (blueScore > (redScore + 1))) {
		blueSet++;
		blueScore = 0;
		redScore = 0;
		service = !initialService;
    initialService = service;
	}
	else if ((redScore >= numPoints) && (redScore > (blueScore + 1))) {
		redSet++;
		blueScore = 0;
		redScore = 0;
		service = !initialService;
    initialService = service;
   }
	
}
void finalMatch() {
	if (blueSet >= ((numSets / 2) + 1)) {
		blueMatch++;
		blueSet = 0;
		redSet = 0;
		service = !initialMatchService;
		initialMatchService = service;
    initialService = service;
	}
	if (redSet >= ((numSets / 2) + 1)) {
		redMatch++;
		blueSet = 0;
		redSet = 0;
		service = !initialMatchService;
    initialMatchService = service;
    initialService = service;
	}

}


/*
##################################draw screens##########################
*/


void drawBaseScreen() {

	vga.copy((byte*)img_varname_data);
}

void drawSelectPoint() {

	vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str36, 35, 12, 3);
	vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, "11", 20, 40, 3);
	vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, "15", 90, 40, 3);

}

void drawSelectSets() {

	vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str35, 35, 12, 3);
	vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, "3", 20, 40, 3);
	vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, "5", 90, 40, 3);

}

void drawSelectService() {

	vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str34, 35, 30, 3);

}

void drawScore() {
  
  vga.printSTR((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, playerRed, 25, 3, 3);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str33, 20, 10, 3);
  vga.printSTR((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, custom_itoa(redMatch), 30, 17, 3);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str32, 25, 25, 3);
  vga.printSTR((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, custom_itoa(redSet), 30, 32, 3);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str31, 20, 40, 3);
  vga.printSTR((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, custom_itoa(redScore), 30, 47, 3);
 
 
  
  vga.printSTR((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, playerBlue, 80, 3, 3);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str33, 80, 10, 3);
  vga.printSTR((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, custom_itoa(blueMatch), 90, 17, 3);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str32, 85, 25, 3);
  vga.printSTR((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, custom_itoa(blueSet), 90, 32, 3);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str31, 80, 40, 3);
  vga.printSTR((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, custom_itoa(blueScore), 90, 47, 3);
  
  
	if (service == 0) {
    vgaU.draw_circle(50, 47,2,3,3);
	}
	else if (service == 1) {
    vgaU.draw_circle(70, 47,2,3,3);
	}
}

void setup() {
	vga.begin();
	//Serial.begin(9600);
	drawBaseScreen();
	//SET PIN BUTTON
	DDRA &= ~(1 << DDA0);
	DDRA &= ~(1 << DDA1);

}

void loop() {

	analyzeButton();
	
	if (stategame == 0) {
		drawSelectPoint();
	} else if (stategame == 1) {
		drawSelectSets();
	} else if (stategame == 2) {
		drawSelectService();
	} else if (stategame == 3) {
		drawScore();
	}
 
	vga.delay(13);
}

