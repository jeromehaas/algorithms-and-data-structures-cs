
// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "array.h"

// FUNCTION: TEST CREATE AND APPEND
static void test_create_and_append(void) {

	// CREATE ARRAY
	Array *arr = create_array();

	// MAKE ASSERTIONS
	assert(arr != NULL);
	assert(arr->size == 0);
	assert(append(arr, 10));
	assert(arr->size == 1);
	assert(get(arr, 0) == 10);

	// FREE MEMORY
	free_array(arr);
}

// FUNCTION: TEST INSERT
static void test_insert(void) {

	// CREAT ARRAY
	Array *arr = create_array();

	// APPEND DATA
	append(arr, 1);
	append(arr, 3);

	// MAKE ASSERTION
	assert(insert(arr, 1, 2));
	assert(arr->size == 3);
	assert(get(arr, 0) == 1);
	assert(get(arr, 1) == 2);
	assert(get(arr, 2) == 3);

	// FREE MEMORY
	free_array(arr);

}

// FUNCTION: TEST REMOVE
static void test_remove(void) {

	// CREATE ARRAY
	Array *arr = create_array();

	// APPEND ITEMS
	append(arr, 1);
	append(arr, 2);
	append(arr, 3);

	// REMOVE ITEM
	int v = remove_at(arr, 1);

	// MAKE ASSERTIONS
	assert(v == 2);
	assert(arr->size == 2);
	assert(get(arr, 1) == 3);

	// FREE MEMORY
	free_array(arr);

}

// FUNCTION TEST GET SET
static void test_get_set(void) {

	// CREATE ARRAY
	Array *arr = create_array();

	// APPEND ITEM
	append(arr, 5);

	// MAKE ASSERTIONS
	assert(get(arr, 0) == 5);
	assert(set(arr, 0, 8));
	assert(get(arr, 0) == 8);
	assert(!set(arr, 1, 3));

	// FREE MEMORY
	free_array(arr);

}

// FUNCTION: TEST RESIZE
static void test_resize(void) {

	// CREATE ARRAY
	Array *arr = create_array();

	// LOOP OVER ARRAY
	for (int i = 0; i < 100; i++) {

		// MAKE ASSERTIONS
		assert(append(arr, i));

	}

	// MAKE ASSERTIONS
	assert(arr->size == 100);

	// LOOP OVER ARRAY
	for (int i = 0; i < 100; i++) {

		// MAKE ASSERTIONS
		assert(get(arr, i) == i);
	}

	// FREE MEMORY
	free_array(arr);

}

// FUNCTION: RUN TESTS
void run_tests(void) {

	// RUN ALL TESTS
	test_create_and_append();
	test_insert();
	test_remove();
	test_get_set();
	test_resize();

	// PRINT SUCCESS MESSAGES
	printf("ALL TESTS PASSED!");

}
