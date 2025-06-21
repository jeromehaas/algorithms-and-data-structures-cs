// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "selection-sort.h"

// FUNCTION: TEST CASES
static void testCases(void) {

	// SETUP VALUES
	int array[] = {3, 6, 1, 5, 5, 7, 2, 9};
	int size = sizeof(array) / sizeof(array[0]);

	// RUN SELECTION SORT
	selectionSort(array, size);

	// VERIFY SORTED ORDER
	int expected[] = {1,2,3,5,5,6,7,9};

	// CHECK FOR ASSERTIONS
	for (int i = 0; i < size; i++) {
		assert(array[i] == expected[i]);
	}

	// PRINT SUCCESS MESSAGE
	printf("ALL TESTS PASSED!");

}

// FUNCTION: RUN TESTS
void run_tests(void) {

	// RUN TEST CASES
	testCases();

}
