// IMPORTS
#include <stdbool.h>
#include "bubble-sort.h"

// FUNCTION: BUBBLE SORT
void bubbleSort(int array[], int size) {

	// FLAG: IS-SORTED
	bool isSorted = false;

	// WHILE LOOP -> LOOP AS LONG AS NOT SORTED
	while (!isSorted) {

		// UPDATE FLAG -> EXPECT CODE TO BE SORTED
		isSorted = true;

		// LOOP OVER VALUES
		for (int i = 0; i < size - 1; i++) {

			// CHECK IF VALUE ON CURRENT INDEX IS BIGGER THAN THE VALUE ON THE NEXT INDEX
			if (array[i] > array[i + 1]) {
				// CREATE TEMPORARY VALUE OF VALUE WITH CURRENT INDEX

				int temp = array[i];

				// SWAP THE VALUES
				array[i] = array[i + 1];
				array[i + 1] = temp;

				// UPDATE FLAG -> SINCE ITERATION HAD A CHANGE ITS LIKELY TO BE NOT SORTED YET
				isSorted = false;
			}

		}

	}

}

