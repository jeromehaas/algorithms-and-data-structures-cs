// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "merge-sort.h"

// SINGLE TEST SUITE
static void testCases(void) {

  	// SETUP VALUES
	int data[] = {3, 6, 1, 5, 5, 7, 2, 9};
	int expected[] = {1, 2, 3, 5, 5, 6, 7, 9};
	int size = sizeof(data) / sizeof(data[0]);

    // SORT
	mergeSort(data, 0, size - 1);

    // LOOP OVER DATA
	for (int i = 0; i < size; i++) {
		assert(data[i] == expected[i]);
	}

 	// PRINT SUCCESS MESSAGE
	printf("ALL TESTS PASSED!");

}

// FUNCTION: RUN TESTS
void run_tests(void) {

  	// RUN TEST CASES
	testCases();

}
