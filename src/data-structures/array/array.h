// CHECK DEF
#ifndef ARRAY_H
#define ARRAY_H

// IMPORTS
#include <stdbool.h>

// DEFINE INITIAL CAMACITY
#define INITIAL_CAPACITY 4

// ARRAY TYPE
typedef struct Array {
	int *data;      /* pointer to elements */
	int size;       /* number of elements */
	int capacity;   /* allocated capacity */
} Array;

// FUNCTION: CREATE ARRAY
Array *create_array(void);

// FUNCTION: APPEND
bool append(Array *array, int value);

// FUNCTION: INSERT
bool insert(Array *array, int index, int value);

// FUNCTION: REMOVE AT
int remove_at(Array *array, int index);

// FUNCTION: GET
int get(Array *array, int index);

// FUNCTION: SET
bool set(Array *array, int index, int value);

// FUNCTION: PRINT ARRAY
void print_array(const Array *array);

// FUNCTION: FREE ARRAY
void free_array(Array *array);

// END DEF
#endif
