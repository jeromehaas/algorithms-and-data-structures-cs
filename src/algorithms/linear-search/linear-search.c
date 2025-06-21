// IMPORTS
#include "linear-search.h"

// FUNCTION: LINEAR SEARCH
int linearSearch(int array[], int size, int value) {

	// LOOP OVER DATA
	for (int i = 0; i < size; i++) {

		// CHECK IF MATCH IS FOUND
		if (array[i] == value) {
			return i;
		}

	}

	// RETURN -1 WHEN NO ITEM IS FOUND
	return -1;

}
