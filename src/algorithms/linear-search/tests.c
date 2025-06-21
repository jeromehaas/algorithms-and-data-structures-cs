// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "linear-search.h"

// FUNCTION: TEST FOUND
static void testFound(void) {

	// DEFINE DATA
	int arr[] = {1, 2, 3, 4};

	// EXECUTE SEARCH
	assert(linearSearch(arr, 4, 3) == 2);

}

// FUNCTION: TEST NOT FOUND
static void testNotFound(void) {

	// DEFINE DATA
	int arr[] = {1, 2, 3, 4};

	// EXECUTE SEARCH
	assert(linearSearch(arr, 4, 5) == -1);

}

// FUNCTION: TEST EMPTY
static void testEmpty(void) {

	// DEFINE DATA
	int arr[] = {};

	// EXECUTE SEARCH
	assert(linearSearch(arr, 0, 1) == -1);

}

// FUNCTION: RUN TESTS
void run_tests(void) {

	// RUN TESTS
	testFound();
	testNotFound();
	testEmpty();

	// PRINT SUCCESS MESSAGE
	printf("ALL TEST PASSED!");

}
