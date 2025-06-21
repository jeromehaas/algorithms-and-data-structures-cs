// IMPORTS
#include "merge-sort.h"
#include <stdlib.h>

// FUNCTION: MERGE
static void merge(int array[], int left, int mid, int right) {

	// CALCULATE THE NUMBER OF ELEMENTS IN EACH HALF
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L = malloc(n1 * sizeof(int));
	int *R = malloc(n2 * sizeof(int));

	// COPY ELEMENTS OF THE LEFT SUBARRAY INTO L[]
	for (int i = 0; i < n1; i++) {
		L[i] = array[left + i];
	}

	// COPY ELEMENTS OF THE RIGHT SUBARRAY INTO R[]
	for (int j = 0; j < n2; j++) {
		R[j] = array[mid + 1 + j];
	}

	// INITIALIZE INDICES FOR L[], R[] AND MERGED ARRAY
	int i = 0, j = 0, k = left;

	// MERGE THE TWO SUBARRAYS BACK INTO ARRAY[LEFT..RIGHT]
	while (i < n1 && j < n2) {

		// PICK THE SMALLER OF L[I] OR R[J] AND PUT IT INTO ARRAY[K]
		if (L[i] <= R[j]) {
			array[k++] = L[i++];
		} else {
			array[k++] = R[j++];
		}

	}

	// COPY ANY REMAINING ELEMENTS OF L[], IF THERE ARE ANY
	while (i < n1) {
		array[k++] = L[i++];
	}

	// COPY ANY REMAINING ELEMENTS OF R[], IF THERE ARE ANY
	while (j < n2) {
		array[k++] = R[j++];
	}

	// FREE MEMORY
	free(L);
	free(R);

}

// FUNCTION: MERGE SORT
void mergeSort(int array[], int left, int right) {

	// CHECK IF LEFT IS SMALLER
	if (left < right) {

		// FIND THE MIDPOINT TO DIVIDE THE ARRAY
		int mid = left + (right - left) / 2;

		// RECURSIVELY SORT FIRST AND SECOND HALVES
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);

		// MERGE THE SORTED HALVES
		merge(array, left, mid, right);

	}

}
