// IMPORTS
#include "binary-search.h"


// FUNCTION: BINARY SEARCH
int binarySearch(int array[], int size, int value) {

	// DEFINE THE INITIAL BOUNDS OF THE SEARCH INTERVAL
	int left = 0;
	int right = size - 1;

	// CONTINUE SEARCHING WHILE THERE IS A VALID INTERVAL
	while (left <= right) {

		// COMPUTE THE MIDPOINT TO SPLIT THE INTERVAL IN HALF
		int mid = left + (right - left) / 2;

		// IF THE TARGET IS AT MID, RETURN ITS INDEX
		if (array[mid] == value) {
			return mid;
		}

		// IF THE TARGET IS LARGER THAN THE MID ELEMENT -> DISCARD THE LEFT HALF BY MOVING LEFT BOUND
		else if (array[mid] < value) {
			left = mid + 1;
		}

		// OTHERWISE, THE TARGET IS SMALLER -> DISCARD THE RIGHT HALF BY MOVING RIGHT BOUND
		else {
			right = mid - 1;
		}

	}

	// IF WE EXIT THE LOOP, THE TARGET IS NOT IN THE ARRAY
	return -1;

}
