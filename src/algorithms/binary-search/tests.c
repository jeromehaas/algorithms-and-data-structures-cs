// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "binary-search.h"

// FUNCTION: TEST FOUND MIDDLE
static void testFoundMiddle(void) {
	int arr[] = {1, 2, 3, 4, 5};
	assert(binarySearch(arr, 5, 3) == 2);
}

// FUNCTION: TEST FOUND FIRST
static void testFoundFirst(void) {
	int arr[] = {10, 20, 30};
	assert(binarySearch(arr, 3, 10) == 0);
}

// FUNCTION: TEST FOUND LAST
static void testFoundLast(void) {
	int arr[] = {10, 20, 30};
	assert(binarySearch(arr, 3, 30) == 2);
}

// FUNCTION: TEST NOT FOUND
static void testNotFound(void) {
	int arr[] = {5, 10, 15};
	assert(binarySearch(arr, 3, 7) == -1);
}

// FUNCTION: TEST EMPTY
static void testEmpty(void) {
	int *arr = NULL;
	assert(binarySearch(arr, 0, 1) == -1);
}

// FUNCTION: RUN TESTS
void run_tests(void) {

	// RUN ALL TESTS
	testFoundMiddle();
	testFoundFirst();
	testFoundLast();
	testNotFound();
	testEmpty();

	// PRINT SUCCESS MESSAGE
	printf("ALL TESTS PASSED!");

}