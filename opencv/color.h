#pragma once
#pragma once
#include <iostream>
#include <Windows.h>

//Console Text Color Manager

#define col GetStdHandle (STD_OUTPUT_HANDLE)
#define SetColor_Red SetConsoleTextAttribute (col, 0x000c );
#define SetColor_Blue SetConsoleTextAttribute (col, 0x0001 | 0x0008 );
#define SetColor_Green SetConsoleTextAttribute (col, 0x0001 | 0x0008 );
#define SetColor_White SetConsoleTextAttribute (col, 0x000f );
#define SetColor_Skyblue SetConsoleTextAttribute (col, 0x000b );
#define SetColor_Yellow SetConsoleTextAttribute (col, 0x000e );
#define SetColor_Chemical SetConsoleTextAttribute (col, 0x000d );
#define SetColor_Gold SetConsoleTextAttribute (col, 0x0006 );
#define SetColor_Wine SetConsoleTextAttribute (col, 0x0005 );
#define SetColor_Blood SetConsoleTextAttribute (col, 0x0004 );
#define SetColor_Violet SetConsoleTextAttribute (col, 0x0001 | 0x0008 | 0x000c );