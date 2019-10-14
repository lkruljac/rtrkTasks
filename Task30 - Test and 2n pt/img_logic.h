#ifndef IMG_LOGIC_H
#define IMG_LOGIC_H

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"img.h"

#include"StackModule.h"
//#include "..\Dependenicies\StackModule\include\StackModule.h"

//mode of search
#define SAME 1
#define DIFFERENT 0



int isPixelAvailable(int x, int y, int height, int weight);
int getTargetvalue(IMG image, int x, int y, int mode);
void searchPixels(IMG image, int x, int y, int mode, int *matchedNumber, Stack **outputPixels);
void printPixelsCoordinates(PIXEL *outputPixels, int matchedNumber);
void printPixelsAsImg(IMG image, Stack outputPixels, int matchedNumber);

#endif 