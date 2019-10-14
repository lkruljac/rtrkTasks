#ifndef IMG_H
#define IMG_H

#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>


typedef struct IMG {
	int height;
	int weight;
	//representing the img file as 2d array
	int **data;
}IMG;


FILE *openFile(char *fileName);

void getDimensions(FILE *file, int *height, int *weight);
int **allocateArray(int height,int weight);
IMG loadImg(FILE *file);
void printImg(IMG image);

#endif
