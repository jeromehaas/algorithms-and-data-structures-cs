// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "stack.h"

// FUNCTION: TEST CREATE AND PUSH PEEK
static void test_create_and_push_peek(void) {

	// CREATE STACK
	Stack *s = createStack();

	// MAKE ASSERTIONS
	assert(s != NULL);
	assert(s->top == 0);

	// PUSH NEW ITEM
	push(s, 5);

	// MAKE ASSERTIONS
	assert(s->top == 1);
	assert(peek(s) == 5);

	// PUSH NEW ITEM
	push(s, 17);

	// MAKE ASSERTIONS
	assert(s->top == 2);
	assert(peek(s) == 17);

	// REMOVE ITEM
	pop(s);

	// MAKE ASSERTION
	assert(s->top == 1);
	assert(peek(s) == 5);

	// FREE MEMORY
	free(s);

}

// FUNCTION: TEST OVERFLOW
static void test_overflow(void) {

	// CREATE STACK
	Stack *s = createStack();

	// LOOP OVER STACK
	for (int i = 1; i <= STACK_CAPACITY; i++) {

		// PUSH NEW ITEMS
		push(s, i);

	}

	// PUSH ITEM
	push(s, 99);

	// MAKE ASSERTIOSN
	assert(s->top == STACK_CAPACITY);

	// MAKE ASSERTIONS
	assert(peek(s) == STACK_CAPACITY);

	// FREE MEMORY
	free(s);

}

// FUNCTION: TEST UNDERFLOW
static void test_underflow(void) {

	// CREATE STACK
	Stack *s = createStack();

	// MAKE ASSERTIONS
	assert(pop(s) == -1);

	// ADD NEW ITEM
	push(s, 1);

	// MAKE ASSERTION
	assert(pop(s) == 1);
	assert(pop(s) == -1);

	// FREE MEMORY
	free(s);

}

// FUNCTION: RUN TESTS
void run_tests(void) {

	// RUN ALL TESTS
	test_create_and_push_peek();
	test_overflow();
	test_underflow();

	// PRINT TEST MESSAGES
	printf("ALL TESTS PASSED!");

}
