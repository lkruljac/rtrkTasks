#include"DLLModule.h"
#include<stdlib.h>
#include<stdio.h>



__declspec(dllexport) NODE* DLLInit(DATA firstElementData) {
	NODE* newHeadNode;
	newHeadNode = (NODE*)malloc(sizeof(NODE));
	
	//writing data of first element
	newHeadNode->data = firstElementData;

	//seting next element on NULL
	newHeadNode->nextNode = NULL;
	//seting previous element on NULL
	newHeadNode->previousNode = NULL;
	return newHeadNode;
}


__declspec(dllexport) NODE* AddElementInDLL(DATA elementToAdd, NODE* headElementOfSLL) {
	NODE* newNode;
	newNode = (NODE*)malloc(sizeof(NODE));

	//there is 2 possibility:
	//1) New NODE is nextElement of last added NODE
	//2) New NODE nextElement is last added NODE
	
	//Here is choosed option 2
	newNode->nextNode = headElementOfSLL;
	headElementOfSLL->previousNode = newNode;
	newNode->data = elementToAdd;

	//because of choosing option number 2 newNode is newHead, 
	//so when calling function in way "currentHead = AddElementInSLL(...), will set currentHead on newNode
	return newNode;

}

__declspec(dllexport) NODE* DeleteElementInDLL(int index, NODE* headElementOfSLL) {
	NODE* newHead = headElementOfSLL;
	if (index == 0) {
		newHead = headElementOfSLL->nextNode;
		newHead->previousNode = NULL;
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

		//now we link previous and next node of target node to each other
		//with both(previous, next) link
		oneBeforeTargetNode->nextNode = targetNode->nextNode;
		targetNode->nextNode->previousNode = oneBeforeTargetNode;

		//after that we can delete
		free(targetNode);
	}
	return newHead;
}

//this function depend on how DATA type is organized, in this case is for just one integer
__declspec(dllexport) void PrintDLL(NODE* head) {
	/*
	if (head != CheckLoop(head)) {
		printf("There is no tail in SLL");
		return;
	}
	*/
	printf("\nDLL from head to tail:\n");
	NODE* currentNode = head;
	while (currentNode != NULL) {
		printf("%d\t", currentNode->data.data);
		currentNode = currentNode->nextNode;
	}
	printf("End of DLL");
}

NODE* getDLLElementByIndex(NODE* head, int index) {
	int i;
	NODE* currentNode = head;
	for (i = 0; i < index; i++) {
		currentNode = currentNode->nextNode;
	}
	return currentNode;
}


int getDLLLenght(NODE* head) {
	int len = 0;
	NODE* currentNode = head;
	while (currentNode != NULL) {
		currentNode = currentNode->nextNode;
		len++;
	}
	return len;
}

NODE* InvertDLL(NODE* head)
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

__declspec(dllexport) NODE* getDLLFromMiddle(NODE* head) {
	NODE* newDLL;
	int len = getDLLLenght(head);
	int midd = len / 2;
	newDLL = DLLInit(getDLLElementByIndex(head, midd)->data);
	
	int i;
	for (i = 1; i < midd; i++) {
		newDLL = AddElementInDLL(getDLLElementByIndex(head, midd - i)->data, newDLL);
		newDLL = AddElementInDLL(getDLLElementByIndex(head, midd + i)->data, newDLL);
	}
	if (len % 2 == 0) {
		newDLL = AddElementInDLL(getDLLElementByIndex(head, 0)->data, newDLL);
	}
	newDLL = InvertDLL(newDLL);
	return newDLL;
}

__declspec(dllexport) NODE* DeleteDLL(NODE* head) {
	NODE* current = head;
	NODE* next;
	while (current != NULL) {
		next = current->nextNode;
		free(current);
		current = next;
	}
	return current;
}