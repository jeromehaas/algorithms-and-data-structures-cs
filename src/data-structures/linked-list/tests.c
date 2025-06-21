// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "linked-list.h"

// FUNCTION: TEST CREATE AND APPEND
static void test_create_and_append(void) {

	// CREATE LIST
	List *l = create_list();

	// MAKE ASSERTIONS
	assert(l != NULL);
	assert(l->size == 0);

	// APPEND ITEM
	append(l, 10);

	// MAKE ASSERTIONS
	assert(l->size == 1);
	assert(l->head != NULL && l->head->data == 10);

	// APPEND ITEM
	append(l, 20);

	// MAKE ASSERTIONS
	assert(l->size == 2);
	assert(l->head->next != NULL && l->head->next->data == 20);

	// FREE MEMORY
	free_list(l);

}

// FUNCTION: TEST PRINT-LIST
static void test_printList(void) {

	// CREATE LIST
	List *l = create_list();

	// APPEND ITEMS
	append(l, 1);
	append(l, 2);
	append(l, 3);

	// PRINT LIST
	printList(l);

	// FREE MEMORY
	free_list(l);

}

// FUNCTION: RUN TESTS
void run_tests(void) {

	// RUN ALL TESTS
	test_create_and_append();
	test_printList();

	// PRINT SUCCESS MESSAGE
	printf("ALL TESTS PASSED!");

}
