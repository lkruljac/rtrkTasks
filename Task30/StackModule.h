#ifndef STACKMOUDLE_H
#define STACKMOUDLE_H


#include<stdlib.h>
#include<stdio.h>

#define SM_DATATYPE PIXEL


//SM_DATA Type
typedef struct PIXEL {
	int x;
	int y;
	int value;
}PIXEL;



typedef struct StackElement {
	SM_DATATYPE data;
	StackElement *next;
	StackElement *previous;
}StackElement;


typedef struct Stack {
	int numOfElements;
	StackElement *last;
	StackElement *first;
}Stack;



__declspec(dllexport) void SM_stackInit(Stack *head);
__declspec(dllexport) int SM_isEmpty(Stack stack);
__declspec(dllexport) void SM_addStackElement(Stack *stack, SM_DATATYPE element);
__declspec(dllexport) void SM_deleteStackElement(Stack *stack, int n);
__declspec(dllexport) void SM_deleteStack(Stack *stack);
__declspec(dllexport) void SM_printStackElement(StackElement *element, Stack stack);
__declspec(dllexport) void SM_printStack(Stack stack);
__declspec(dllexport) PIXEL SM_getElement(Stack* stack, int n);

#endif
