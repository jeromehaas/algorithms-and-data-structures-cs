// IMPORTS
#include "quick-sort.h"
#include <stdlib.h>

// FUNCTION: SWAP
static void swap(int *a, int *b) {

	// CREATE TEMPORARY VALUE
	int tmp = *a;

	// SWAP ITEMS
	*a = *b;
	*b = tmp;

}

// FUNCTION: PARTITION ARRAY
static int partition(int array[], int low, int high) {

	// CHOOSE THE LAST ELEMENT AS PIVOT
	int pivot = array[high];

	// INDEX OF THE SMALLER ELEMENT; ELEMENTS ≤ PIVOT WILL GO TO THE LEFT
	int i = low - 1;

	// ITERATE OVER THE SUBARRAY [LOW..HIGH-1]
	for (int j = low; j < high; j++) {

		// IF CURRENT ELEMENT IS ≤ PIVOT, MOVE IT TO THE "SMALLER" SIDE
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}

	}

	// PLACE PIVOT IMMEDIATELY AFTER THE LAST SMALLER ELEMENT
	swap(&array[i + 1], &array[high]);

	// RETURN THE PIVOT'S FINAL POSITION
	return i + 1;

}

// FUNCTION: QUICK SORT
void quickSort(int array[], int low, int high) {

	// ONLY PROCEED IF THE SUBARRAY CONTAINS MORE THAN ONE ELEMENT
	if (low < high) {

		// PARTITION THE ARRAY AND GET PIVOT INDEX
		int part = partition(array, low, high);

		// RECURSIVELY SORT ELEMENTS BEFORE PIVOT
		quickSort(array, low, part - 1);

		// RECURSIVELY SORT ELEMENTS AFTER PIVOT
		quickSort(array, part + 1, high);

	}

}
