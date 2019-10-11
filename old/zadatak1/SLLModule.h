//SSL means Singly Linked List


typedef struct UserDataElement {
	//define your data here;
	//example of representing data as just one integer called "data"
	int data;
}DATA;

typedef struct BaseNodeContent {
	//This pointer should be casted every time because data type can be modifyed by user in file "userDataElement.h"
	DATA data;
	struct BaseNodeContent* nextNode;
}NODE;


//Initialization SSL means that we are creating new head node, and adding first element
//function return newHead
NODE* SSLInit(DATA firstElementData);

//Function recive 2 parametars, first one is element we wanna add, and 2nd one is head of SLL where we it should be added
//Function return head of edited SLL
NODE* AddElementInSLL(DATA elementToAdd, NODE* headElementOfSLL);

//Function recive 2 parametars, first one is index of element we wanna delete
//and 2nd one is head of SLL where we are deleting element
//first(head) index is 0,
//Function return head of edited SLL
NODE* DeleteElementInSLL(int index, NODE* headElementOfSLL);