#include"DLLModule.h"
#include<stdio.h>
#include<conio.h>

int main() {
	NODE* head;
	DATA myFirstElement;
	myFirstElement.data = 0;

	//Testing Init function
	printf("Added first element: %d", myFirstElement.data);
	head = DLLInit(myFirstElement);
	PrintDLL(head);

	//Testing AddElement function
	int i;
	DATA element;
	for (i = 1; i < 11; i++) {
		element.data = i;
		head = AddElementInDLL(element, head);
	}
	PrintDLL(head);

	//Test DeleteElement function
	int index = 3;
	printf("\nDeleted element on index: %d", index);
	head = DeleteElementInDLL(index, head);
	PrintDLL(head);

	//Test Divide function

	//Test DeleteSLL function
	printf("\nDeleted SSL");
	head = DeleteDLL(head);
	PrintDLL(head);


	printf("\n###\n###\nUser press any key to exit...");
	_getch();

	return 0;
}