// CHECK DEF
#ifndef LIST_H
#define LIST_H

// IMPORTS
#include <stdio.h>
#include <stdlib.h>

// NODE TYPE
typedef struct Node {
	int data;
	struct Node *next;
	struct Node *previous;
} Node;

// LIST TYPE
typedef struct List {
	int size;
	Node *head;
	Node *tail;
} List;

// FUNCTION: CREATE LIST
List *create_list(void);

// FUNCTION: ADD
void add(List *list, int data);

// FUNCTION: APPEND
void append(List *list, int data);

// FUNCTION: INSERT
int insert(List *list, int index, int data);

// FUNCTION: DELETE
int delete(List *list, int index);

// FUNCTION: TRAVERSE
void traverse(const List *list);

// FUNCTION: FREE LIST
void free_list(List *list);

// END DEF
#endif