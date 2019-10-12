#include"SLLModule.h"
#include<stdlib.h>
#include<stdio.h>



NODE* SLLInit(DATA firstElementData) {
	NODE* newHeadNode;
	newHeadNode = (NODE*)malloc(sizeof(NODE));

	//writing data of first element
	newHeadNode->data = firstElementData;

	//seting next element on NULL
	newHeadNode->nextNode = NULL;
	return newHeadNode;
}


NODE* AddElementInSLL(DATA elementToAdd, NODE* headElementOfSLL) {
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

 NODE* DeleteElementInSLL(int index, NODE* headElementOfSLL) {

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
void PrintSLL(NODE* head) {
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


NODE* DeleteSLL(NODE* head) {
	NODE* current = head;
	NODE* next;
	while (current != NULL) {
		next = current->nextNode;
		free(current);
		current = next;
	}
	return current;
}

void DivideSLL(NODE* head, NODE** aSLL, NODE** bSLL) {
	NODE* currentNode=head;
	int index = 0;

	while (currentNode != NULL) {
		if (index == 0) {
			//init aSLL
			*aSLL = SLLInit(currentNode->data);
		}
		else if (index == 1) {
			//init bSLL
			*bSLL = SLLInit(currentNode->data);
		}
		else if (index % 2 == 0) {
			//add to aSLLL
			*aSLL = AddElementInSLL(currentNode->data, *aSLL);
		}
		else if (index % 2 == 1) {
			//add to bSLL
			*bSLL = AddElementInSLL(currentNode->data, *bSLL);
		}
		index++;
		currentNode = currentNode->nextNode;
	}
}