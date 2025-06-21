// IMPORTS
#include "doubly-linked-list.h"
#include <stdlib.h>
#include <stdio.h>

// FUNCTION: CREATE LIST
List *create_list(void) {

	// CREATE LIST
	List *list = malloc(sizeof(List));

	// CHECK IF LIST EXISTS
	if (!list) return NULL;

	// SET HEAD AND SIZE DEFAULT VALUE
	list->head = list->tail = NULL;
	list->size = 0;

	// RETURN
	return list;

}

// FUNCTION CREATE NODE
Node *create_node(int data) {

	// CREATE NODE
	Node *new_node = malloc(sizeof(Node));

	// CHECK IF NODE EXISTS
	if (!new_node) return NULL;

	// SET DATA
	new_node->data = data;
	new_node->next = new_node->prev = NULL;

	// RETURN
	return new_node;

}

// FUNCTION: APPEND
void append(List *list, int data) {

	// CREATE NODE
	Node *new_node = create_node(data);

	// CHECK IF CODE EXISTS
	if (!new_node) return;

	// WHEN EMPTY CREATE HEAD AND SET TAIL -> ELSE DEFINE PREV AND TAIL
	if (list->size == 0) {
		list->head = list->tail = new_node;
	} else {
		new_node->prev      = list->tail;
		list->tail->next    = new_node;
		list->tail          = new_node;
	}

	// INCREASE SIZE
	list->size++;

}

// FUNCTION: PRINT LIST
void printList(const List *list) {

	// GET CURRENT NODE (HEAD)
	Node *current = list->head;

	// LOOP OVER CURRENT
	while (current) {

		// PRINT DATA OF CURRENT
		printf("%d ", current->data);

		// TRAVERST TO THE NEXT
		current = current->next;

	}

}

// FUNCTION: FREE LIST
void free_list(List *list) {

	// GET CURRENT (HEAD)
	Node *current = list->head;

	// LOOP OVER CURRENT
	while (current) {

		// GET NEXT NODE
		Node *next = current->next;

		// FREE MEMORY
		free(current);

		// TRAVERSE TO NEXT NODE
		current = next;

	}

	// FREE MEMORY
	free(list);

}
