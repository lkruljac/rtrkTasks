#include"img.h"
#include"img_logic.h"

#include"StackModule.h"
//#include "..\Dependenicies\StackModule\include\StackModule.h"


int main() {
	
	FILE *file;
	//edit this line
	char fileName[] = "..\\Task30 - Test and 2n pt\\test30\\img3.txt";
	file = (FILE*)openFile(fileName);
	if (file == NULL) {
		printf("Open file error");
		return 0;
	}
	IMG image;

	//loading data
	image = loadImg(file);

	//check loaded
	printImg(image);

	//scan the target pixel
	int x, y;
	do {
		printf("\nInsert point:\n\tx:\t");
		scanf("%d", &x);
		printf("\ty:\t");
		scanf("%d", &y);
		//checking is target pixel avilabel
		if (!isPixelAvailable(x, y, image.height, image.weight)) {
			printf("Invalid input\n");
		}
	} while (!isPixelAvailable(x, y, image.height, image.weight));
	


	//logic
	Stack *outputPixels;
	outputPixels = (Stack*)malloc(sizeof(Stack));
	
	SM_stackInit(outputPixels);
	int matchedNumber;
	searchPixels(image, x, y, DIFFERENT, &matchedNumber, &outputPixels);
	
	//reload img
	file = (FILE*)openFile(fileName);//bug ako se iznova ne otvori, èita samo 1 red
	image = loadImg(file);


	//print results
	printf("\n#######\nOutput\n#######\n\n");
	SM_printStack(*outputPixels);
	printf("\n\n");
	printPixelsAsImg(image, *outputPixels, matchedNumber);


	printf("MyPress any key to exit...\n");
	getchar();
	getchar();

	return 0;
}