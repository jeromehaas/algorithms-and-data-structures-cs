// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "list.h"

// FUNCTION: TEST ADD AND APPEND
static void test_add_and_append(void) {

	// CREATE LIST
	List *l = create_list();

	// MAKE ASSERTIONS
	assert(l != NULL);
	assert(l->size == 0);

	// ADD ITEM
	add(l, 10);  // [10]

	// MAKE ASSERTIONS
	assert(l->size == 1);
	assert(l->head->data == 10 && l->tail->data == 10);

	// ADD ITEM
	append(l, 20);  // [10,20]

	// MAKE ASSERTIONS
	assert(l->size == 2);
	assert(l->head->data == 10);
	assert(l->tail->data == 20);

	// FREE MEMORY
	free_list(l);

}

// FUNCTION: TEST INSERT MIDDLE
static void test_insert_middle(void) {

	// CREATE LIST
	List *l = create_list();

	// APPEND ITEMS
	append(l, 1);
	append(l, 3);

	// INSERT ITEM
	int item = insert(l, 1, 2);  // [1,2,3]

	// MAKE ASSERTIONS
	assert(item == 1);
	assert(l->size == 3);

	// CREATE NODE
	Node *n = l->head;

	// MAKE ASSERTIONS AND TRAVERSE
	assert(n->data == 1);
	n = n->next;
	assert(n->data == 2);
	n = n->next;
	assert(n->data == 3);

	// FREE MEMORY
	free_list(l);

}

// FUNCTION: TEST DELETE HEAD OF TAIL MIDDLE
static void test_delete_head_tail_middle(void) {

	// CREATE LIST
	List *l = create_list();

	// APPEND ITEMS
	append(l, 1);
	append(l, 2);
	append(l, 3);

	// MAKE ASSERTIONS
	assert(delete(l, 0) == 1);
	assert(l->size == 2);
	assert(l->head->data == 2);
	assert(delete(l, l->size - 1) == 1);
	assert(l->size == 1);
	assert(l->tail->data == 2);

	// APPEND ITEMS
	append(l, 3);
	append(l, 4);

	// MAKE ASSERTIONS
	assert(delete(l, 1) == 1);
	assert(l->size == 2);

	// CREATE NODE
	Node *n = l->head->next;

	// MAKE ASSERTIONS
	assert(n->data == 4);

	// FREE MEMORY
	free_list(l);

}

// FUNCTION: TEST INVALID PROPS
static void test_invalid_ops(void) {

	// CREATE LIST
	List *l = create_list();

	// MAKE ASSERTIONS
	assert(insert(l, 5, 100) == 0);
	assert(delete(l, 0) == 0);

	// FREE LIST
	free_list(l);

}

// FUNCTION: RUN TESTS
void run_tests(void) {

	// RUN ALL TESTS
	test_add_and_append();
	test_insert_middle();
	test_delete_head_tail_middle();
	test_invalid_ops();

	// PRINT SUCCESS MESSAGE
	printf("ALL TESTS PASSED!");

}
