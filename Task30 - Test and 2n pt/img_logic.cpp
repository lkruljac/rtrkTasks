#include "img_logic.h"


#include"StackModule.h"
//#include "..\Dependenicies\StackModule\include\StackModule.h"

void writeMatchedPixels(int ** array, PIXEL * matchedPixelsArray)
{

}

int getTargetvalue(IMG image, int x, int y, int mode) {
	if ((mode == 1 && image.data[y][x] == 1) || (mode == 0 && image.data[y][x] == 0)) {
		return  1;
	}
	else {
		return 0;
	}
}

int isPixelAvailable(int x, int y, int height, int weight) {
	if (x < 0 || y < 0 || x >= weight || y >= height) {
		return 0;
	}
	return 1;
}

void addPixels(Stack *stack, int startX, int startY, IMG *image, int targetValue, int *matchedNumber) {
	int i, j;

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	printf("\n\n");
	
	for (i = 0; i < image->height; i++) {
		for (j = 0; j < image->weight; j++) {
			if (startY == i && startX == j) {
				SetConsoleTextAttribute(hConsole, 4);
				printf("%d\t", image->data[i][j]);
			}
			else if (image->data[i][j] == -1) {
				SetConsoleTextAttribute(hConsole, 15);
				printf("%d\t", image->data[i][j]);
			}
			else {
				SetConsoleTextAttribute(hConsole, 2);
				printf("%d\t", image->data[i][j]);
			}
		}
		SetConsoleTextAttribute(hConsole, 15);
		printf("\n");
	}

	printf("\n\n");

	
	PIXEL *newPixel;

	for (i = startY - 1; i <= startY + 1; i++) {
		for (j = startX - 1; j <= startX + 1; j++) {
			if (!isPixelAvailable(j, i, image->height, image->weight)) {
				//do nothing
			}
			else if (image->data[i][j] == targetValue) {
				newPixel = (PIXEL*)malloc(sizeof(PIXEL));
				if (newPixel == NULL) {
					printf("Error, low memory");
				}
				newPixel->value = image->data[i][j];
				newPixel->y = i;
				newPixel->x = j;

				SM_addStackElement(stack, *newPixel);
				image->data[i][j] = -1;
				(*matchedNumber)++;
			}
		}
	}
}

void searchPixels(IMG image, int x, int y, int mode, int *matchedNumber, Stack **outputPixels)
{
	int targetValue;
	targetValue = getTargetvalue(image, x, y, mode);


	//Using MyStackModule here
		
	Stack *pixels;
	pixels = (Stack*)malloc(sizeof(Stack));
	SM_stackInit(pixels);


	PIXEL first;

	first.value = image.data[y][x];
	first.x = x;
	first.y = y;
	SM_addStackElement(pixels, first);

	image.data[y][x] = -1;
	int i;
	*matchedNumber = 1;

	PIXEL currentPixel;
	for (i = 0; i <= *matchedNumber; i++) {

		currentPixel = SM_getElement(pixels, i);
		currentPixel = SM_getElement(pixels, i);

		addPixels(pixels, currentPixel.x, currentPixel.y, &image, targetValue, matchedNumber);

	}

	//return
	*outputPixels = pixels;
}

void printPixelsCoordinates(PIXEL *outputPixels, int matchedNumber)
{
	int i;
	for (i = 1; i < matchedNumber; i++) {
		printf("(%d, %d)\t%d\n", outputPixels[i].x, outputPixels[i].y, outputPixels[i].value);
	}
}

void printPixelsAsImg(IMG image, Stack outputPixels, int matchedNumber)
{

	int i, j;
	char **charImage;
	charImage = (char**)malloc(image.height * sizeof(char*));
	for (i = 0; i < image.height; i++) {
		charImage[i] = (char*)malloc(image.weight * sizeof(char));
	}

	for (i = 0; i < image.height; i++) {
		for (j = 0; j < image.weight; j++) {
			charImage[i][j] = '#';
		}
	}


	PIXEL currentPixel;
	for (i = 0; i <= matchedNumber; i++) {
		
		currentPixel = SM_getElement(&outputPixels, i);
		currentPixel = SM_getElement(&outputPixels, i);
		charImage[currentPixel.y][currentPixel.x] = currentPixel.value + 48;

	}



	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 5);

	SetConsoleTextAttribute(hConsole, 15);
	printf("\n\n");

	PIXEL firstPixel;
	firstPixel = SM_getElement(&outputPixels, 0);
	firstPixel = SM_getElement(&outputPixels, 0);

	for (i = 0; i < image.height; i++) {
		for (j = 0; j < image.weight; j++) {
			if (firstPixel.y == i && firstPixel.x == j) {
				SetConsoleTextAttribute(hConsole, 4);
				printf("%d ", image.data[i][j]);
			}
			else if (charImage[i][j] == '#') {
				SetConsoleTextAttribute(hConsole, 15);
				printf("%d ", image.data[i][j]);
			}
			else {
				SetConsoleTextAttribute(hConsole, 2);
				printf("%d ", image.data[i][j]);
			}
		}
		printf("\t");
		for (j = 0; j < image.weight; j++) {
			if (firstPixel.y == i && firstPixel.x == j) {
				SetConsoleTextAttribute(hConsole, 204);
				printf("%d ", image.data[i][j]);
			}
			else if (charImage[i][j] == '#') {
				if (image.data[i][j] == 1) {
					SetConsoleTextAttribute(hConsole, 153);
					printf("%d ", image.data[i][j]);
				}
				else {
					SetConsoleTextAttribute(hConsole, 170);
					printf("%d ", image.data[i][j]);
				}
			}
			else {
				SetConsoleTextAttribute(hConsole, 238);
				printf("%d ", image.data[i][j]);
			}
		}	
		SetConsoleTextAttribute(hConsole, 15);
		printf("\n\r");
	}
	SetConsoleTextAttribute(hConsole, 15);


}

