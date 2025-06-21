// CHECK DEF
#ifndef AVL_H
#define AVL_H

// NODE TYPE
typedef struct Node {
	int key;
	int height;
	struct Node *left;
	struct Node *right;
} Node;

// FUNCTION: INSERT
Node* insert(Node *node, int key);

// FUNCTION: DELETE NODE
Node* deleteNode(Node *node, int key);

// FUNCTION: PRE-ORDER
void preOrder(Node *root);

// END DEF
#endif