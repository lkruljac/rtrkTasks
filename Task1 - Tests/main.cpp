#include"SLLModule.h"
#include<stdio.h>

int main() {
	NODE *head;
	DATA myFirstElement;
	myFirstElement.data = 0;
	
	//Testing Init function
	printf("Added first element: 1");
	head = SSLInit(myFirstElement);
	PrintSSL(head);

	//Testing AddElement function
	int i;
	DATA element;
	for (i = 1; i < 11; i++) {
		element.data = i;
		head = AddElementInSLL(element, head);
	}
	PrintSSL(head);

	//Test DeleteElement function
	int index = 3;
	printf("\nDeleted element on index: %d", index);
	head = DeleteElementInSLL(index, head);
	PrintSSL(head);


	return 0;
}