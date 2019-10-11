#include"SLLModule.h"
#include<stdlib.h>



extern NODE* SSLInit(DATA firstElementData) {
	NODE *newHeadNode;
	newHeadNode = (NODE*)malloc(sizeof(NODE));
	
	//writing data of first element
	newHeadNode->data = firstElementData;

	//seting next element on NULL
	newHeadNode->nextNode = NULL;
	return newHeadNode;
}


extern NODE* AddElementInSLL(DATA elementToAdd, NODE* headElementOfSLL) {
	NODE *newNode;
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

extern NODE* DeleteElementInSLL(int index, NODE* headElementOfSLL){

	NODE* newHead = headElementOfSLL;
	if (index == 0) {
		newHead = headElementOfSLL->nextNode;
		//now we can delete node on index 0, or headnode
		free(headElementOfSLL);
	}
	else {
		int i;
		NODE *oneBeforeTargetNode = headElementOfSLL;
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
