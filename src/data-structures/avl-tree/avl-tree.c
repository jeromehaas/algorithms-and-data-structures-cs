// IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include "avl-tree.h"

// RETURN HEIGHT OF NODE OR 0 IF NODE IS NULL
static int height(Node *node)
{
    // IF NODE IS NULL
    if (!node)
    {
        // RETURN 0 FOR NULL NODE
        return 0;
    }
    // RETURN NODE HEIGHT
    return node->height;
}

// RETURN LARGEST OF TWO INTEGERS
static int max(int a, int b)
{
    // IF A > B
    if (a > b)
    {
        // RETURN A
        return a;
    }
    // RETURN B
    return b;
}

// ALLOCATE AND INITIALIZE NEW NODE WITH GIVEN KEY
static Node* newNode(int key)
{
    // ALLOCATE MEMORY FOR NODE
    Node *node = malloc(sizeof(Node));

    // SET NODE KEY
    node->key = key;

    // SET INITIAL HEIGHT
    node->height = 1;

    // INITIALIZE CHILD POINTERS TO NULL
    node->left = NULL;
    node->right = NULL;

    // RETURN NEW NODE
    return node;

}

// RIGHT ROTATION TO BALANCE TREE
static Node* rightRotate(Node *y)
{
    // SET X TO LEFT CHILD OF Y
    Node *x = y->left;

    // MOVE X'S RIGHT SUBTREE TO Y'S LEFT
    y->left = x->right;

    // MAKE Y RIGHT CHILD OF X
    x->right = y;

    // UPDATE HEIGHT OF Y
    y->height = 1 + max(height(y->left), height(y->right));

    // UPDATE HEIGHT OF X
    x->height = 1 + max(height(x->left), height(x->right));

    // RETURN NEW ROOT X
    return x;

}

// LEFT ROTATION TO BALANCE TREE
static Node* leftRotate(Node *x)
{
    // SET Y TO RIGHT CHILD OF X
    Node *y = x->right;

    // MOVE Y'S LEFT SUBTREE TO X'S RIGHT
    x->right = y->left;

    // MAKE X LEFT CHILD OF Y
    y->left = x;

    // UPDATE HEIGHT OF X
    x->height = 1 + max(height(x->left), height(x->right));

    // UPDATE HEIGHT OF Y
    y->height = 1 + max(height(y->left), height(y->right));

    // RETURN NEW ROOT Y
    return y;

}

// COMPUTE BALANCE FACTOR OF NODE (HEIGHT(LEFT) - HEIGHT(RIGHT))
static int getBalance(Node *node)
{
    // RETURN BALANCE FACTOR
    return height(node->left) - height(node->right);

}

// INSERT KEY INTO AVL TREE AND REBALANCE IF NEEDED
Node* insert(Node *node, int key)
{
    // IF NODE IS NULL, CREATE NEW NODE
    if (!node)
    {
        // RETURN NEW NODE AS ROOT
        return newNode(key);

    }

    // IF KEY LESS THAN NODE KEY, INSERT INTO LEFT SUBTREE
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }

    // ELSE IF KEY GREATER THAN NODE KEY, INSERT INTO RIGHT SUBTREE
    else if (key > node->key)
    {
        node->right = insert(node->right, key);

    // ESLE DUPLICATE KEY, DO NOTHING
    } else {

        // RETURN UNCHANGED NODE
        return node;

    }

    // UPDATE HEIGHT OF ANCESTOR NODE
    node->height = 1 + max(height(node->left), height(node->right));

    // COMPUTE BALANCE FACTOR TO CHECK FOR ROTATIONS
    int balance = getBalance(node);

    // IF LEFT LEFT CASE
    if (balance > 1 && key < node->left->key)
    {

        // RETURN RIGHT ROTATION
        return rightRotate(node);

    }

    // IF RIGHT RIGHT CASE
    if (balance < -1 && key > node->right->key)
    {

        // RETURN LEFT ROTATION
        return leftRotate(node);

    }

    // IF LEFT RIGHT CASE
    if (balance > 1 && key > node->left->key)
    {
        // PERFORM LEFT ROTATION ON LEFT CHILD
        node->left = leftRotate(node->left);

        // RETURN RIGHT ROTATION ON NODE
        return rightRotate(node);

    }

    // IF RIGHT LEFT CASE
    if (balance < -1 && key < node->right->key)
    {
        // PERFORM RIGHT ROTATION ON RIGHT CHILD
        node->right = rightRotate(node->right);

        // RETURN LEFT ROTATION ON NODE
        return leftRotate(node);

    }

    // RETURN NODE AFTER INSERTION AND BALANCING
    return node;

}

// FIND MINIMUM VALUE NODE IN SUBTREE
static Node* minValueNode(Node *node)
{

    // WHILE LEFT CHILD EXISTS, TRAVERSE LEFT
    while (node->left) {
        node = node->left;
    }

    // RETURN LEFTMOST NODE
    return node;

}

// DELETE KEY FROM AVL TREE AND REBALANCE IF NEEDED
Node* deleteNode(Node *node, int key)
{

    // IF TREE IS EMPTY
    if (!node) {

        // RETURN NULL
        return NULL;

    }

    // IF KEY TO DELETE IS SMALLER, GO LEFT
    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    }

    // IF KEY TO DELETE IS LARGER, GO RIGHT
    else if (key > node->key) {
        node->right = deleteNode(node->right, key);

    // OTHERWISE KEY IS SAME AS NODE
    } else {

        // IF NODE HAS AT MOST ONE CHILD
        if (!node->left || !node->right) {
            Node *temp = node->left ? node->left : node->right;

            // NO CHILD CASE
            if (!temp) {

                // FREE NODE AND RETURN NULL
                free(node);
                return NULL;

            }

            // ONE CHILD CASE: COPY CHILD DATA
            *node = *temp;
            free(temp);

        } else {

            // NODE HAS TWO CHILDREN: GET INORDER SUCCESSOR
            Node *temp = minValueNode(node->right);

            // COPY SUCCESSOR KEY
            node->key = temp->key;

            // DELETE SUCCESSOR
            node->right = deleteNode(node->right, temp->key);

        }

    }

    // UPDATE HEIGHT
    node->height = 1 + max(height(node->left), height(node->right));

    // GET BALANCE FACTOR FOR ROTATIONS
    int balance = getBalance(node);

    // IF LEFT LEFT CASE AFTER DELETION
    if (balance > 1 && getBalance(node->left) >= 0) {

        // RETURN RIGHT ROTATION
        return rightRotate(node);

    }

    // IF LEFT RIGHT CASE AFTER DELETION
    if (balance > 1 && getBalance(node->left) < 0) {

        // PERFORM LEFT ROTATION ON LEFT CHILD
        node->left = leftRotate(node->left);

        // RETURN RIGHT ROTATION
        return rightRotate(node);

    }

    // IF RIGHT RIGHT CASE AFTER DELETION
    if (balance < -1 && getBalance(node->right) <= 0) {

        // RETURN LEFT ROTATION
        return leftRotate(node);

    }

    // IF RIGHT LEFT CASE AFTER DELETION
    if (balance < -1 && getBalance(node->right) > 0) {

        // PERFORM RIGHT ROTATION ON RIGHT CHILD
        node->right = rightRotate(node->right);

        // RETURN LEFT ROTATION
        return leftRotate(node);

    }

    // RETURN NODE AFTER DELETION AND BALANCING
    return node;

}

// PRINT TREE KEYS IN PRE-ORDER: ROOT, LEFT, RIGHT
void preOrder(Node *root) {
    // IF NODE IS NULL, RETURN
    if (!root) {
        return;
    }

    // PRINT CURRENT NODE KEY
    printf("%d ", root->key);

    // RECURSE ON LEFT SUBTREE
    preOrder(root->left);

    // RECURSE ON RIGHT SUBTREE
    preOrder(root->right);

}