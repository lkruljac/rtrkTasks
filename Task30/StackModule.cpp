#include "StackModule.h"

__declspec(dllexport) void SM_stackInit(Stack *head)
{
	head->first = NULL;
	head->last = NULL;
	head->numOfElements = 0;
}

__declspec(dllexport) void SM_addStackElement(Stack *stack, SM_DATATYPE element)
{
	StackElement *newElement;
	newElement = (StackElement*)malloc(1 * sizeof(StackElement));
	newElement->data = element;

	if (stack->numOfElements == 0) {
		stack->numOfElements++;
		stack->last = newElement;
		stack->first = newElement;
		newElement->next = NULL;
		newElement->previous = NULL;
	}
	else {
		newElement->next = NULL;
		newElement->previous = stack->last;
		stack->last->next = newElement;
		stack->numOfElements++;
		stack->last = newElement;
	}
}


__declspec(dllexport) int SM_isEmpty(Stack stack) {
	if (stack.last == NULL && stack.first == NULL) {
		return 1;
	}
	return 0;
}

__declspec(dllexport) int countStack(Stack stack) {
	return stack.numOfElements;
}

__declspec(dllexport) void SM_deleteStackElement(Stack *stack, int n)
{
	if (stack->numOfElements == n + 1) {
		stack->last = stack->last->previous;

	}
	else {
		int i;
		StackElement *targetElement;
		targetElement = stack->first;
		for (i = 1; i < n; i++) {
			targetElement = targetElement->next;
		}
		if (targetElement->previous != NULL) {
			targetElement->previous->next = targetElement->next;
		}
		if (targetElement->next != NULL) {
			targetElement->next->previous = targetElement->previous;
		}
		free(targetElement);
		stack->numOfElements--;
	}
}



__declspec(dllexport) void SM_deleteStack(Stack *stack)
{
	if (stack->numOfElements != 0) {
		SM_deleteStackElement(stack, stack->numOfElements);
	}
}


__declspec(dllexport) void printPixel(PIXEL pixel) {
	printf("(%d, %d) : %d\n", pixel.x, pixel.y, pixel.value);
}


__declspec(dllexport) void SM_printStackElement(StackElement *element, Stack stack) {

	if (element->previous == stack.first) {
		printPixel(element->data);
		printPixel(element->previous->data);
	}
	else {
		//error if data type is not integer
		printPixel(element->data);
		SM_printStackElement(element->previous, stack);
	}
}

__declspec(dllexport) void SM_printStack(Stack stack)
{
	printf("Stack is:\t\n");
	SM_printStackElement(stack.last, stack);
	printf("\n");
}

__declspec(dllexport) PIXEL SM_getElement(Stack* stack, int n) {
	
	if (n == 0) {
		return stack->first->data;
	}
	StackElement *targetElement;
	int i;
	targetElement = stack->first;
	for (i = 1; i < n; i++) {
		targetElement = targetElement->next;
	}
	return targetElement->data;

}