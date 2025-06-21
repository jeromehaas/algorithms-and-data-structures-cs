// IMPORTS
#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>

// FUNCTION: CREATE LIST
List *create_list(void) {

	// CREATE LIST
	List *list = malloc(sizeof(List));

	// CHECK IF LIST EXISTS
	if (!list) return NULL;

	// DEFINE DEFAULT VALUES
	list->head = NULL;
	list->size = 0;

	// RETURN
	return list;

}

// FUNCTION: APPEND
void append(List *list, int data) {

	// CREATE NODE
	Node *new_node = malloc(sizeof(Node));

	// CHECK FOR NODE AND TERMINATE IF IT DOESN'T EXIST
	if (!new_node) return;

	// SET DATA AND SET NEXT TO NULL
	new_node->data = data;
	new_node->next = NULL;

	// IF NO HEAD EXIST
	if (!list->head) {

		// DEFINE HEAD WITH NEW NODE
		list->head = new_node;

	// IF HAS HEAD
	} else {

		// GET HEAD AND MAKE IT NEW HEAD
		Node *cur = list->head;

		// TRAVERSE TROUGH LIST AND GET LAST NODE
		while (cur->next) {
			cur = cur->next;
		}

		// MAKE LAST NODE THE NEXT
		cur->next = new_node;
	}

	// INCREASE SIZE
	list->size++;

}

// FUNCTION: PRINT LIST
void printList(const List *list) {

	// CREATE NODE
	Node *cur = list->head;

	// LOOP OVER NODE
	while (cur) {

		// SET NEXT
		cur = cur->next;
	}

}

// FUNCTION: FREE LIOST
void free_list(List *list) {

	// CREATE NODE (HEAD)
	Node *cur = list->head;

	// TRAVERSE TROUGH LIST
	while (cur) {

		// GET NODE
		Node *next = cur->next;

		// FREE MEMORY
		free(cur);

		// GET NEXT NODE
		cur = next;

	}

	// FREE MEMORY
	free(list);

}
