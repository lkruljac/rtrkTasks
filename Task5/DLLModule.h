//DLL means double linked list

#include"userDataElement.h"

__declspec(dllexport) typedef struct BaseNodeContent {
	//This pointer should be casted every time because data type can be modifyed by user in file "userDataElement.h"
	DATA data;
	struct BaseNodeContent* nextNode;
	struct BaseNodeContent* previousNode;
}NODE;


//Initialization SSL means that we are creating new head node, and adding first element
//function return newHead
__declspec(dllexport) NODE* DLLInit(DATA firstElementData);

//Function recive 2 parametars, first one is element we wanna add, and 2nd one is head of SLL where we it should be added
//Function return head of edited SLL
__declspec(dllexport) NODE* AddElementInDLL(DATA elementToAdd, NODE* headElementOfSLL);

//Function recive 2 parametars, first one is index of element we wanna delete
//and 2nd one is head of SLL where we are deleting element
//first(head) index is 0,
//Function return head of edited SLL
__declspec(dllexport) NODE* DeleteElementInDLL(int index, NODE* headElementOfSLL);

__declspec(dllexport) void PrintDLL(NODE* head);

__declspec(dllexport) NODE* CheckLoop(NODE* head);

__declspec(dllexport) NODE* DeleteDLL(NODE* head);
