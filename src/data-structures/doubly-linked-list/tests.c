// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "doubly-linked-list.h"

// FUNCTION: TEST CREATE APPEND
static void test_create_append(void) {

	// CREATE LIST
	List *l = create_list();

	// MAKE ASSERTSIONS
	assert(l != NULL);
	assert(l->size == 0);

	// APPEND ITEM
	append(l, 5);

	// MAKE ASSERTIONS
	assert(l->size == 1);
	assert(l->head == l->tail);
	assert(l->head->data == 5);

	// APPEND ITEM
	append(l, 7);

	// MAKE ASSERTIONS
	assert(l->size == 2);
	assert(l->head->data == 5);
	assert(l->tail->data == 7);

	// FREE LIST
	free_list(l);

}

// FUNCTION: TEST LINKS
static void test_links(void) {

	// CREATE LIST
	List *l = create_list();

	// APPEND ITEMS
	append(l, 1);
	append(l, 2);
	append(l, 3);

	// GET NODES
	Node *n1 = l->head;
	Node *n2 = n1->next;
	Node *n3 = n2->next;

	// MAKE ASSERTIONS
	assert(n1->prev == NULL);
	assert(n1->data == 1);
	assert(n2->prev == n1 && n2->next == n3 && n2->data == 2);
	assert(n3->next == NULL && n3->prev == n2 && n3->data == 3);

	// FREE LIST
	free_list(l);

}

// FUNCTION: RUN TESTS
void run_tests(void) {

	// RUN ALL TESTS
	test_create_append();
	test_links();

	// PRINT SUCCESS MESSAGE
	printf("ALL TESTS PASSED!");

}

