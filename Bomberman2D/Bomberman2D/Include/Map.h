#pragma once
#include "main.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 13

#define MAP_OFFSET_X 50
#define MAP_OFFSET_Y 50

#define MAP_WIDTH_SCALE 2
#define MAP_HEIGHT_SCALE 2

#define SIZE_BLOCK 50

#define GET_POSITON_X(column)  MAP_OFFSET_X + SIZE_BLOCK * column 
#define GET_POSITON_Y(row)  MAP_OFFSET_Y + SIZE_BLOCK * row


const char mapLevel1[MAP_HEIGHT][MAP_WIDTH] = {
"|||||||||||||||||||",
"|-----------------|",
"|-|-|-|-|-|-|-|-|-|",
"|-----------------|",
"|-|-|-|-|-|-|-|-|-|",
"|-----------------|",
"|-|-|-|-|-|-|-|-|-|",
"|-----------------|",
"|-|-|-|-|-|-|-|-|-|",
"|-----------------|",
"|-|-|-|-|-|-|-|-|-|",
"|-----------------|",
"|||||||||||||||||||"
};

