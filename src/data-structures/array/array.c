// IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

// FUNCTION: CREATE ARRAY
Array *create_array(void) {

  // SETUP ARRAY STRUCT
  Array *array = (Array *) malloc(sizeof(Array));

  // TERMINATE IF NO ARRAY
  if (!array) return NULL;

  // ALLOCATE DATA BUFFER
  array->data = (int *) malloc(INITIAL_CAPACITY * sizeof(int));

  // IF ARRAY HAS NO DATA -> FREE MEMORY AND TERMINATE
  if (!array->data) {
    free(array);
    return NULL;
  };

  // SET DEFAULT VALUES
  array->size = 0;
  array->capacity = INITIAL_CAPACITY;

  // RETURN
  return array;

};

// FUNCTION: RESIZE BUFFER
static bool resize(Array *array, int new_capacity) {

  // CREATE TEMPORARY VALUE
  int *tmp = (int *) realloc(array->data, new_capacity * sizeof(int));

  // TERMINATE IF HAS NO TEMPORARY VALUE
  if (!tmp) return false;

  // SET DATA AND CAPACITY
  array->data = tmp;
  array->capacity = new_capacity;

  // RETURN
  return true;

};

// FUNCTION: APPEND
bool append(Array *array, int value) {

  // GROW IF NEEDED
  if (array->size >= array->capacity) {
    if (!resize(array, array->capacity * 2)) return false;
  };

  // ADD VALUE
  array->data[array->size++] = value;

  // RETURN
  return true;

};

// FUNCTION: INSERT

bool insert(Array *array, int index, int value) {
  // VALIDATE INDEX
  if (index < 0 || index > array->size) {

    // RETURN
    return false;

  };

  // COMPARE SIZE AND CAPACITY
  if (array->size >= array->capacity) {

    // TERMINATE IF NO CAPACITY
    if (!resize(array, array->capacity * 2)) return false;
  };

  // LOOP OVER ARRAY
  for (int i = array->size; i > index; i--) {

    // SHIFT ELEMENTS TO THE RIGHT
    array->data[i] = array->data[i - 1];

  };

  // INSERT NEW VALUE
  array->data[index] = value;
  array->size++;
  return true;
};

// FUNCTION: REMOVE AT INDEX
int remove_at(Array *array, int index) {
  // VALIDATE INDEX
  if (index < 0 || index >= array->size) {
    return -1;
  };

  // STORE AND REMOVE
  int value = array->data[index];

  // LOOP OVER ARRAY
  for (int i = index; i < array->size - 1; i++) {

    // UPDATE DATA
    array->data[i] = array->data[i + 1];

  };

  // DECREASE ARRAY SIZE
  array->size--;

  // RETURN
  return value;

};

// FUNCTION: GET
int get(Array *array, int index) {

  // VALIDATE INDEX
  if (index < 0 || index >= array->size) {

    // RETURN -1
    return -1;
  };

  // RETURN INDEX
  return array->data[index];

};

// FUNCTION: SET
bool set(Array *array, int index, int value) {

  // VALIDATE INDEX AND TERMINATE IF NOT VALID
  if (index < 0 || index >= array->size) {
    return false;
  };

  // SET DATA
  array->data[index] = value;

  // RETURN
  return true;

};

// FUNCTION: PRINT ARRAY
void print_array(const Array *array) {

  // PRINT OVER ARRAY
  for (int i = 0; i < array->size; i++) {

    // PRINT DATA
    printf("%d ", array->data[i]);
  };

  // PRINT LINE-BREAK
  printf("\n");

};

// FUNCTION: FREE ARRAY
void free_array(Array *array) {

  // FREE MEMORY
  free(array->data);
  free(array);

};
