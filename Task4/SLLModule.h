//SLL means Singly Linked List

#include"userDataElement.h"
__declspec(dllexport)
__declspec(dllexport) typedef struct BaseNodeContent {
	//This pointer should be casted every time because data type can be modifyed by user in file "userDataElement.h"
	DATA data;
	struct BaseNodeContent* nextNode;
}NODE;


//Initialization SSL means that we are creating new head node, and adding first element
//function return newHead
__declspec(dllexport) NODE* SLLInit(DATA firstElementData);

//Function recive 2 parametars, first one is element we wanna add, and 2nd one is head of SLL where we it should be added
//Function return head of edited SLL
__declspec(dllexport) NODE* AddElementInSLL(DATA elementToAdd, NODE* headElementOfSLL);

//Function recive 2 parametars, first one is index of element we wanna delete
//and 2nd one is head of SLL where we are deleting element
//first(head) index is 0,
//Function return head of edited SLL
__declspec(dllexport) NODE* DeleteElementInSLL(int index, NODE* headElementOfSLL);

__declspec(dllexport) void PrintSLL(NODE* head);

__declspec(dllexport) NODE* InvertSLL(NODE *head);

__declspec(dllexport) NODE* DeleteSLL(NODE* head);