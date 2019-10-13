#include"SLLModule.h"
#include<stdlib.h>
#include<stdio.h>



__declspec(dllexport) NODE* SLLInit(DATA firstElementData) {
	NODE* newHeadNode;
	newHeadNode = (NODE*)malloc(sizeof(NODE));

	//writing data of first element
	newHeadNode->data = firstElementData;

	//seting next element on NULL
	newHeadNode->nextNode = NULL;
	return newHeadNode;
}


__declspec(dllexport) NODE* AddElementInSLL(DATA elementToAdd, NODE* headElementOfSLL) {
	NODE* newNode;
	newNode = (NODE*)malloc(sizeof(NODE));

	//there is 2 possibility:
	//1) New NODE is nextElement of last added NODE
	//2) New NODE nextElement is last added NODE
	//Here is choosed option 2
	newNode->nextNode = headElementOfSLL;
	newNode->data = elementToAdd;

	//because of choosing option number 2 newNode is newHead, 
	//so when calling function in way "currentHead = AddElementInSLL(...), will set currentHead on newNode
	return newNode;

}

__declspec(dllexport) NODE* DeleteElementInSLL(int index, NODE* headElementOfSLL) {

	NODE* newHead = headElementOfSLL;
	if (index == 0) {
		newHead = headElementOfSLL->nextNode;
		//now we can delete node on index 0, or headnode
		free(headElementOfSLL);
	}
	else {
		int i;
		NODE* oneBeforeTargetNode = headElementOfSLL;
		for (i = 0; i < index - 1; i++) {
			oneBeforeTargetNode = oneBeforeTargetNode->nextNode;
		}
		NODE* targetNode;
		targetNode = oneBeforeTargetNode->nextNode;

		//now we link previous and next node of target node
		oneBeforeTargetNode->nextNode = targetNode->nextNode;

		//after that we can delete

	}
	return newHead;

}

//this function depend on how DATA type is organized, in this case is for just one integer
__declspec(dllexport) void PrintSLL(NODE* head) {
	/*
	if (head != CheckLoop(head)) {
		printf("There is no tail in SLL");
		return;
	}
	*/
	printf("\nSLL from head to tail:\n");
	NODE* currentNode = head;
	while (currentNode != NULL) {
		printf("%d\t", currentNode->data.data);
		currentNode = currentNode->nextNode;
	}
	printf("End of SLL");
}


__declspec(dllexport) NODE* DeleteSLL(NODE* head) {
	NODE* current = head;
	NODE* next;
	while (current != NULL) {
		next = current->nextNode;
		free(current);
		current = next;
	}
	return current;
}

__declspec(dllexport) NODE* InvertSLL(NODE* head) 
{
	// no need to reverse if head is nullptr 
	// or there is only 1 node.
	if (head == NULL || head->nextNode == nullptr) {
		return head;
	}

	NODE* list_to_do = head->nextNode;

	NODE* reversedList = head;
	reversedList->nextNode = nullptr;

	while (list_to_do != nullptr) {
		NODE* temp = list_to_do;
		list_to_do = list_to_do->nextNode;

		temp->nextNode = reversedList;
		reversedList = temp;
	}

	return reversedList;
}