// IMPORTS
#include "selection-sort.h"

// FUNCTION: SELECTION SORT
void selectionSort(int array[], int size) {

	// LOOP OVER ARRAY -> SET THE CURRENT INDEX AS THE POSITION TO FILL
	for (int i = 0; i < size - 1; i++) {

		// INITIALIZE THE INDEX OF THE MINIMUM VALUE TO THE CURRENT INDEX
		int minIndex = i;

		// LOOP OVER THE UNSORTED PART OF THE ARRAY
		for (int j = i + 1; j < size; j++) {

			// FIND THE INDEX OF THE SMALLEST VALUE
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}

		}

		// CREATE TEMP VALUE
		int temp = array[i];

		// SWAP THE VALUES
		array[i] = array[minIndex];
		array[minIndex] = temp;

	}

}
