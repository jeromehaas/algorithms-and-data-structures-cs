// IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// FUNCTION: CREATE LIST
List *create_list(void) {

  // SETUP LIST
  List *list = (List *) malloc(sizeof(List));

  // CHECK IF LIST IS AVAILABLE
  if (!list) return NULL;

  // SET DEFAULT VALUES
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;

  // RETURN LIST
  return list;

};

// FUNCTION: ADD
void add(List *list, int data) {

  // SETUP NEW NODE
  Node *node = (Node *) malloc(sizeof(Node));

  // APPEND DATA TO NODE
  node->data = data;
  node->next = list->head;
  node->previous = NULL;

  // UPDATE PREVIOUS
  if (list->head != NULL) {
    list->head->previous = node;
  };

  // UPDATE LIST HEAD
  list->head = node;

  // CREATE TAIL IF NOT EXIST
  if (list->tail == NULL) {
    list->tail = node;
  };

  // UPDATE SIZE
  list->size++;

};

// FUNCTION: APPEND
void append(List *list, int data) {

  // CREATE NEW NODE
  Node *node = (Node *) malloc(sizeof(Node));

  // APPEND DATA TO NODE
  node->data = data;
  node->next = NULL;
  node->previous = list->tail;

  // CREATE HEAD IF NOT EXIST
  if (list->head == NULL) {
    list->head = node;
  }

  // UPDATE PREVIOUS OF TAIL
  if (list->tail != NULL) {
    list->tail->next = node;
  }

  // UPDATE TAIL
  list->tail = node;

  // UPDATE SIZE
  list->size++;

};

// FUNCTION: INSERT
int insert(List *list, int index, int data) {

  // CHECK IF INDEX IS VALID
  if (index < 0 || index > list->size) {
    return 0;
  };

  // CREATE NEW NODE
  Node *node = (Node *) malloc(sizeof(Node));

  // APPEND DATA TO NODE
  node->data = data;

  // CREATE HEAD IF NOT EXISTS
  if (list->head == NULL) {
    list->head = node;
  };

  // CREATE TAIL IF NOT EXISTS
  if (list->tail == NULL) {
    list->tail = node;
  };

  // IF NO ENTRIES EXIST
  if (list->size == 0) {

    // UPDATE NODE
    node->next = NULL;
    node->previous = NULL;

    // UPDATE HEAD AND TAIL
    list->head = node;
    list->tail = node;

  };

  // IF INDEX IS ZERO
  if (index <= 0) {

    // UPDATE NODE
    node->next = list->head;
    node->previous = NULL;

    // ADD PREVIOUS TO PREVIOUS HEAD NODE
    list->head->previous = node;

    // UPDATE HEAD
    list->head = node;

  };

  // IF INDEX IS LAST
  if (index >= list->size) {

    // UPDATE NODE
    node->next = NULL;
    node->previous = list->tail;

    // ADD NEXT TO PREVIOUS NODE
    list->tail->next = node;

    // UPDATE TAIL
    list->tail = node;

  };

  // IF INDEX IS BETWEEN ENTRIES
  if (index > 0 && index < list->size) {

    // SETUP TARGET-NODE AND NEW-NODE
    Node *targetNode = (Node *) malloc(sizeof(Node));
    Node *newNode = (Node *) malloc(sizeof(Node));

    // MAKE TARGET NODE TO HEAD NODE
    targetNode = list->head;

    // FIND TARGET-NODE
    for (int i = 0; i < index; i++) {
      targetNode = targetNode->next;
    }

    // DEFINE NEW NODE
    newNode->data = data;
    newNode->next = targetNode;
    newNode->previous = targetNode->previous;

    // UPDATE TARGET-NODE
    targetNode->previous->next = newNode;
    targetNode->previous = newNode;

  };

  // UPDATE SIZE OF LIST
  list->size++;

  // RETURN
  return 1;

};

// FUNCTION: DELETE
int delete(List *list, int index) {

  // CHECK IF INDEX IS VALID
  if (index < 0 || index >= list->size) {
    return 0;
  };

  // SETUP TARGET NODE
  Node *targetNode = (Node*) malloc(sizeof(Node));

  // IF INDEX IS ZERO
  if (index == 0) {

    // UPDATE LIST HEAD
    list->head->next->previous = NULL;
    list->head = list->head->next;
  };

  // IF INDEX TAIL
  if (index >= list->size - 1) {

    // UPDATE TAIL
    list->tail->previous->next = NULL;
    list->tail = list->tail->previous;

  };

  // IF INDEX IS BETWEEN HEAD AND TAIL
  if (index > 0 && index < list->size - 1) {

    // MAKE TARGET NODE TO HEAD NODE
    targetNode = list->head;

    // FIND TARGET-NODE
    for (int i = 0; i < index; i++) {
      targetNode = targetNode->next;
    };

    // UPDATE TARGET-NODE
    targetNode->previous->next = targetNode->next;
    targetNode->next->previous = targetNode->previous;

  };

  // UPDATE SIZE OF LIST
  list->size--;

  // FREE MEMORY FOR TARGET-NODE
  free(targetNode);

  // RETURN
  return 1;

}

// FUNCTION: TRAVERSE
void traverse(const List *list) {

  // SETUP TARGET NODE
  Node *currentNode = (Node *) malloc(sizeof(Node));

  // CHECK IF HEAD IS AVAILABLE
  if (list->head) {

    // INITIALIZE CURRENT NODE
    currentNode = list->head;

    // LOOP OVER ALL ENTRIES
    while (currentNode->data) {

      // UPDATE CURRENT NODE
      currentNode = currentNode->next;

    };

  };

};

// FUNCTION: FREE LIST
void free_list(List *list) {

  // CREATE NEW NODE
  Node *currentNode = list->head;

  // LOOP OVER ENTRIES
  while (currentNode) {

    // FREE UP NODE
    Node *next = currentNode->next;

    // FREE MEMORY
    free(currentNode);

    // UPDATE CURRENT-NODE
    currentNode = next;

  };

  // FREE LIST
  free(list);

};