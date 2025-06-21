// CHECK DEF
#ifndef QUEUE_DYNAMIC_H
#define QUEUE_DYNAMIC_H

// IMPORTS
#include <stdbool.h>

// ELEMENT TYPE
typedef struct Element {
	int data;
	struct Element *next;
} Element;

// QUEUE TYPE
typedef struct Queue {
	Element *front;
	int size;
} Queue;

// FUNCTION: CREATE QUEUE
Queue *createQueue(void);

// FUNCTION: IS EMPTY
bool isEmpty(Queue *queue);

// FUNCTION: ENQUUE
bool enqueue(Queue *queue, int value);

// FUNCTION: DEQUEUE
int dequeue(Queue *queue);

// FUNCTION: PEEK
int peek(Queue *queue);

// END DEF
#endif
