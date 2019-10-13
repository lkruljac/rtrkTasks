#include"SLLModule.h"
#include<stdio.h>
#include<conio.h>

int main() {
	NODE* head;
	DATA myFirstElement;
	myFirstElement.data = 0;

	//Testing Init function
	printf("Added first element: %d", myFirstElement.data);
	head = SLLInit(myFirstElement);
	PrintSLL(head);

	//Testing AddElement function
	int i;
	DATA element;
	for (i = 1; i < 11; i++) {
		element.data = i;
		head = AddElementInSLL(element, head);
	}
	PrintSLL(head);

	//Test DeleteElement function
	int index = 3;
	printf("\nDeleted element on index: %d", index);
	head = DeleteElementInSLL(index, head);
	PrintSLL(head);

	//Test Divide function
	NODE* invertedSLL;
	invertedSLL = InvertSLL(head);
	printf("\nInverted");
	PrintSLL(invertedSLL);

	//Test DeleteSLL function
	printf("\nDeleted SSL");
	head = DeleteSLL(head);
	PrintSLL(head);


	printf("\n###\n###\nUser press any key to exit...");
	_getch();

	return 0;
}