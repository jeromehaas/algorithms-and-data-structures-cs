// START DEF
#ifndef STACK_H
#define STACK_H

// IMPORTS
#include <stdbool.h>

// DEFINE STACK CAPACITY
#define STACK_CAPACITY 3

// STACK TYPE
typedef struct {
	int top;
	int elements[STACK_CAPACITY];
} Stack;

// FUNCTION: CREATE STACK
Stack *createStack(void);

// FUNCTION: PEEK
int peek(Stack *stack);

// FUNCTION: PUSH
void push(Stack *stack, int value);

// FUNCTION: POP
int pop(Stack *stack);

// END DEF
#endif
