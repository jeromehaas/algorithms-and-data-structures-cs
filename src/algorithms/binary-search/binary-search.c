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

#include <cstddef>  // für size_t


void sort(List *list) {
	// Für 0 oder 1 Element ist keine Sortierung nötig
	if (list->size < 2) return;

	bool isSorted = false;
	while (!isSorted) {
		isSorted = true;
		Node *current = list->head;
		// Ein Durchlauf von head bis tail
		while (current->next != NULL) {
			if (current->data > current->next->data) {
				// Tausch der Daten
				int tmp = current->data;
				current->data = current->next->data;
				current->next->data = tmp;
				isSorted = false;
			}
			current = current->next;
		}
	}
}



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct element {
    int data;
    struct element *next;
} Element;

typedef struct {
    Element *front;
    Element *rear;
    int size;
} Queue;

void enqueue(Queue *queue, int data) {
    Element *newElem = (Element *)malloc(sizeof(Element));
    newElem->data = data;
    newElem->next = NULL;

    if (queue->size == 0) {
        // leere Queue
        queue->front = queue->rear = newElem;
    } else {
        // an das Ende anhängen
        queue->rear->next = newElem;
        queue->rear = newElem;
    }
    queue->size++;
}

int dequeue(Queue *queue) {
    if (queue->size == 0) {
        // nichts zum Entfernen
        return -1;
    }

    Element *oldFront = queue->front;
    int value = oldFront->data;

    queue->front = oldFront->next;
    free(oldFront);
    queue->size--;

    if (queue->size == 0) {
        // wenn jetzt leer, auch rear zurücksetzen
        queue->rear = NULL;
    }

    return value;
}

void testCasesEnqueue(Queue* queue){
    enqueue(queue, 5);
    assert(queue->front->data == 5);
    assert(queue->rear->data == 5);
    assert(queue->size == 1);
    enqueue(queue, 3);
    assert(queue->front->next->data == 3);
    assert(queue->rear->data == 3);
    assert(queue->size == 2);
    enqueue(queue, 1);
    assert(queue->rear->data == 1);
    assert(queue->size == 3);

    printf("congratulations all tests for enqueueing passed\n");
}

void testCasesDequeue(Queue* queue){
    dequeue(queue);
    assert(queue->size == 2);
    assert(queue->front->data == 3);
    dequeue(queue);
    assert(queue->size == 1);
    assert(queue->front->data == 1);
    dequeue(queue);
    assert(queue->size == 0);

    printf("congratulations all tests for dequeueing passed\n");
}

int main()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;

    testCasesEnqueue(queue);
    testCasesDequeue(queue);

    // weiterer dequeue auf leerer Queue
    int r = dequeue(queue);
    assert(r == -1); // können hier -1 erwarten

    free(queue);
    return 0;
}

// FUNCTION: CONTAINS VALUE
int containsValue(TreeNode* treeNode, int data) {
	if (treeNode == NULL) {
		// we’ve fallen off the tree without finding it
		return 0;
	}
	if (data == treeNode->data) {
		// found the value!
		return 1;
	}
	else if (data < treeNode->data) {
		// if it’s smaller, it can only live in the left subtree
		return containsValue(treeNode->left, data);
	}
	else {
		// otherwise it can only live in the right subtree
		return containsValue(treeNode->right, data);
	}
}
