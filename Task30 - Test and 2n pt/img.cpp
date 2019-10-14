#include"img.h"
#include"StackModule.h"
//#include "..\Dependenicies\StackModule\include\StackModule.h"

FILE *openFile(char *fileName) {
	FILE *fileptr;
	fileptr = fopen(fileName, "r");
	if (fileptr == NULL) {
		printf("Failed to open %s\n\n", fileName);
		return NULL;
	}
	else
	{
		printf("Successfully open %s\n\n", fileName);
		return fileptr;
	}
}

void getDimensions(FILE *file, int * height, int * weight) {
	*height = 0;
	*weight = 0;
	char c;
	do {
		c = getc(file);
		if (c == ' ' && *height == 0) {
			(*weight)++;
		}
		if (c == '\n') {
			(*height)++;
		}
	} while (c != EOF);
	//after last number is not space character, but there was a number
	(*weight)++;
	
}

int **allocateArray(int height, int weight)
{
	int **array;
	int i;
	array = (int**)malloc((height) * sizeof(int*));
	if (array == NULL) {
		printf("Error during allocationg memory for 2d array");
		return nullptr;
	}
	for (i = 0; i < height; i++) {
		array[i] = (int*)malloc(weight * sizeof(int));
		if (array[i] == NULL) {
			printf("Error during allocationg memory for 2d array");
			return nullptr;
		}
	}

	return array;
}

IMG loadImg(FILE * file)
{
	IMG image;


	//geting dimensions	
	getDimensions(file, &image.height, &image.weight);

	//allocating the memory for data
	image.data = allocateArray(image.height, image.weight);
	if (image.data == NULL) {
		printf("Error!");
		return image;
	}

	//filling the array
	int i, j;
	//reset the file pointer to the start of file
	fseek(file, 0, SEEK_SET);
	for (i = 0; i < image.height; i++) {
		for (j = 0; j < image.weight; j++) {
			fscanf(file, "%d", &image.data[i][j]);
		}
	}

	return image;
}

void printImg(IMG image) {

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int i, j;
	for (i = 0; i < image.height; i++) {
		for (j = 0; j < image.weight; j++) {
			SetConsoleTextAttribute(hConsole, 15);
			if (image.data[i][j] == 1) {
				printf("%d ", image.data[i][j]);
			}
			else {
				printf("%d ", image.data[i][j]);
			}
			
		}
		printf("\t");
		for (j = 0; j < image.weight; j++) {
			if (image.data[i][j] == 1) {
				SetConsoleTextAttribute(hConsole, 153);
				printf("%d ", image.data[i][j]);
			}
			else {
				SetConsoleTextAttribute(hConsole, 170);
				printf("%d ", image.data[i][j]);
			}

		}
		printf("\n");
	}
	SetConsoleTextAttribute(hConsole, 15);
}


