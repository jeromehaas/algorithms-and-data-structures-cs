// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "quick-sort.h"

// FUNCTION: TEST CASES
static void testCases(void) {

  	// DEFINE DATA
	int array[] = {3, 6, 1, 5, 5, 7, 2, 9};
	int expected[] = {1, 2, 3, 5, 5, 6, 7, 9};
	int size = sizeof(array) / sizeof(array[0]);

    // SORT
	quickSort(array, 0, size - 1);

    // LOOP OVER DATA
	for (int i = 0; i < size; i++) {

        // DO CHECKS
		assert(array[i] == expected[i]);

	}

    // PRINT SUCCESS MESSAGE
	printf("ALL TESTS PASSES!");

}

// FUNCTION: RUN TESTS
void run_tests(void) {

  	// RUN TEST CASES
	testCases();

}
