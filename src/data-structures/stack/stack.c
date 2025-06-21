// IMPORTS
#include <stdio.h>
#include <stdlib.h>

// DEFINE CAPACITY
enum { STACK_CAPACITY = 3 };

// STACK TYPE
typedef struct
{
	int top;
	int elements[STACK_CAPACITY];
} Stack;

// FUNCTION: CREATE STACK
Stack *createStack()
{

	// CREATE STACK
	Stack *stack = malloc(sizeof(Stack));

	// SET DEFAULT VALUE FOR TOP
	stack->top = 0;

	// RETURN
	return stack;

}

// FUNCTION: PEEK
int peek(Stack *stack)
{

	// RETURN
	return stack->elements[stack->top - 1];

}

// FUNCTION: PUSH
void push(Stack *stack, int value)
{

	// CHECK FOR MAX CAPACITY
	if (stack->top < STACK_CAPACITY){

		// ADD ITEM
		stack->elements[stack->top++] = value;

	}

}

// FUNCTION: POP
int pop(Stack *stack) {

	// CHECK FOR TOP
	if (stack->top > 0) {

		// REMOVE TOP NODE
		int topElement = stack->elements[--stack->top];

		// RETURN TOP ELEMENT
		return topElement;

	//  IF STACK IS EMPTY
	} else {

		// RETURN
		return -1;

	}

}
