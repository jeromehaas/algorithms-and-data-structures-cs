// CHECK DEF
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

// IMPORTS
#include <stddef.h>

// NODE TYPE
typedef struct Node {
	int data;
	struct Node *next;
} Node;

// LIST TYPE
typedef struct List {
	Node *head;
	size_t size;
} List;

// FUNCTION CREATE LIST
List *create_list(void);

// FUNCTION: APPEND
void append(List *list, int data);

// FUNCTION: PRINT LIST
void printList(const List *list);

// FUNCTION: FREE LIEST
void free_list(List *list);

// END DEF
#endif
