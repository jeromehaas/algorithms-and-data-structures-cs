// IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include "dynamic-queue.h"

// FUNCTION: CREATE QUEUE
Queue *createQueue() {

    // SETUP QUEUE
    Queue *queue = (Queue *) malloc(sizeof(Queue));

    // WHEN QUEUE EXISTS -> SET DEFAULT VALUES
    if (queue) {
        queue->front = NULL;
        queue->size = 0;
    };

    // RETURN
    return queue;

};

// FUNCTION: IS EMPTY
bool isEmpty(Queue *queue) {

    // CHECK IF QUEUE IS EMPTY
    bool isQueueEmpty = queue->size == 0 ? true : false;

    // RETURN
    return isQueueEmpty;

};

// FUNCTION: ENQUEUE
bool enqueue(Queue *queue, int value) {

    // SETUP NODE
    Element *node = malloc(sizeof(Element));

    // SET DEFAULT VALUES IN NODE
    node->data = value;
    node->next = NULL;

     // CHECK IF QUEUE IS EMPTY
    bool isQueueEmpty = queue->size == 0 ? true : false;

    // CHECK IF
    if (!isQueueEmpty) {

        // SETUP NODE
        Element *current = queue->front;

        // TRAVERSE THE QUEUE UNTIL THE LAST NODE IS FOUND
        while (current->next != NULL) {
            current = current->next;
        };

        // THEN ASSIGN THE "NEXT" FROM THE LAST NODE TO THE NEW NODE
        current->next = node;
    }

    // IF THERE ARE NO OTHER NODES IN THE QUEUE -> MAKE THIS NODE THE FRONT ONE
    if (isQueueEmpty) {
        queue->front = node;
    };

    // INCREASE THE SIZE OF THE QUEUE
    queue->size++;

    // RETURN
    return true;

};

// FUNCTION: DEQUEUE
int dequeue(Queue *queue) {

    // CHECK IF QUEUE IS EMPTY
    bool isQueueEmpty = queue->size == 0 ? true : false;

    // IF QUEUE IS EMPTY STOP EXECUTION
    if (isQueueEmpty) {
        return -1;
    };

    // SETUP NODE
    Element *node = queue->front;

    // ASSIGN VALUE TO NODE
    int value = node->data;

    //  THE SECOND NODE BECOMES THE FIRST NODE
    queue->front = node->next;

    // FREE SPACE
    free(node);

    // DECREASE SIZE OF QUEUE
    queue->size--;

    // RETURN
    return value;
};

// FUNCTION: PEEK
int peek(Queue *queue) {

    // CHECK IF QUEUE IS EMPTY
    bool isQueueEmpty = queue->size == 0 ? true : false;

    // IF QUEUE IS EMPTY STOP EXECUTION
    if (isQueueEmpty) {
        return -1;
    };

    // GET DATA OF THE FIRST NODE
    int data = queue->front->data;

    // RETURN
    return data;

};
