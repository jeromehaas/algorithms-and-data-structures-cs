// CHECK DEF
#ifndef LIST_H
#define LIST_H

// IMPORTS
#include <stddef.h>

// NODE TYPE
typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
} Node;

// LIST TYPE
typedef struct list {
	Node *head;
	Node *tail;
	size_t size;
} List;

// FUNCTION: CREATE LIST
List *create_list(void);

// FUNCTION: APPEND
void append(List *list, int data);

// FUNCTION: PRINT LIST
void printList(const List *list);

// FUNCTION: FREE LIST
void free_list(List *list);

// END DEF
#endif
