// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "bubble-sort.h"

// FUNCTION: TEST CASES
static void testCases(void) {

	// SETUP VALUES
	int array[] = {3, 6, 1, 5, 5, 7, 2, 9};

	// DEFINE SIZE OF ARRAY
	int size = sizeof(array) / sizeof(array[0]);

	// RUN BUBBLE SORT
	bubbleSort(array, size);

	// RUN TESTS
	assert(array[0] == 1);
	assert(array[1] == 2);
	assert(array[2] == 3);
	assert(array[3] == 5);
	assert(array[4] == 5);
	assert(array[5] == 6);
	assert(array[6] == 7);
	assert(array[7] == 9);

	// PRINT SUCCESS-MESSAGE IF TEST PASSED
	printf("ALL TEST PASSED!");
}

// FUNCTION: RUN TESTS
void run_tests(void) {

  	// RUN TEST CASES
	testCases();

}
