// IMPORTS
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dynamic-queue.h"

// FUNCTION: TEST CREATE AND EMPTY
static void test_create_and_empty(void) {

	// CREATE QUEUE
	Queue *q = createQueue();

	// MAKE ASSERTIONS
	assert(q != NULL);
	assert(isEmpty(q));

	// FREE MEMORY
	free(q);

}

// FUNCTION: TEST ENQUEUE PEEK
static void test_enqueue_peek(void) {

	// CREATE QUEUE
	Queue *q = createQueue();

	// ENQUEUE
	enqueue(q, 42);

	// MAKE ASSERTIONS
	assert(!isEmpty(q));
	assert(peek(q) == 42);

	// FREE MEMORY
	free(q);

}

// FUNCTION: TEST DEQUEUE ORDER
static void test_dequeue_order(void) {

	// CREATE QUEUE
	Queue *q = createQueue();

	// ENQUEUE
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);

	// MAKE ASSERTIONS
	assert(dequeue(q) == 1);
	assert(dequeue(q) == 2);
	assert(dequeue(q) == 3);
	assert(isEmpty(q));

	// FREE MEMORY
	free(q);

}

// FUNCTION: TEST DEQUEUE EMPTY
static void test_dequeue_empty(void) {

	// CREATE QUEUE
	Queue *q = createQueue();

	// MAKE ASSERTIONS
	assert(dequeue(q) == -1);
	assert(peek(q)    == -1);

	// FREE MEMORY
	free(q);

}

// FUNCTION: RUN TESTS
void run_tests(void) {

	// RUN ALL TESTS
	test_create_and_empty();
	test_enqueue_peek();
	test_dequeue_order();
	test_dequeue_empty();

	// PRINT SUCCESS MESSAGE
	printf("ALL TEST PASSED!");
}

