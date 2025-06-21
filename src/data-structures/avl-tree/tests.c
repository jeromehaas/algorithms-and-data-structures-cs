// IMPORTS
#include <assert.h>
#include <stdio.h>
#include "avl-tree.h"

// FUNCTION ASSERT NODE
static void assert_node(Node *n, int key, int height, int has_left, int has_right) {


    // CHECK EXPECTIONS
    assert(n != NULL);
    assert(n->key == key);
    assert(n->height == height);

    // CHECK LEFT/RIGHT CASES
    if (has_left)  assert(n->left  != NULL);
    else assert(n->left  == NULL);
    if (has_right) assert(n->right != NULL);
    else assert(n->right == NULL);

}

// FUNCTION: TEST RR-ROTATION
static void test_rr_rotation(void) {

    // CREATE NODE
    Node *root = NULL;

    // INSERT VALUES
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    // MAKE ASSERTIONS
    assert_node(root, 20, 2, 1, 1);
    assert_node(root->left, 10, 1, 0, 0);
    assert_node(root->right, 30, 1, 0, 0);

    // DELETE NODES
    root = deleteNode(root, 10);
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);

}

// FUNCTOIN: TEST LL-ROTATION
static void test_ll_rotation(void) {

    // CREATE NODE
    Node *root = NULL;

    // INSERT DATA
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);

    // MAKE ASSERTIONS
    assert_node(root, 20, 2, 1, 1);
    assert_node(root->left, 10, 1, 0, 0);
    assert_node(root->right, 30, 1, 0, 0);

    // DELETE NODES
    root = deleteNode(root, 10);
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);

}

// FUNCTION: TEST LR-ROTATION
static void test_lr_rotation(void) {

    // CREATE NODE
    Node *root = NULL;

    // INSERT DATA
    root = insert(root, 30);
    root = insert(root, 10);
    root = insert(root, 20);

    // MAKE ASSERTIONS
    assert_node(root, 20, 2, 1, 1);
    assert_node(root->left, 10, 1, 0, 0);
    assert_node(root->right, 30, 1, 0, 0);

    // DELETE SOME NODES
    root = deleteNode(root, 10);
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
}

// FUNCTION: TEST RL-ROTATION
static void test_rl_rotation(void) {

    // CREATE NODE
    Node *root = NULL;

    // INSERT DATA
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 20);

    // MAKE ASSERTIONS
    assert_node(root, 20, 2, 1, 1);
    assert_node(root->left, 10, 1, 0, 0);
    assert_node(root->right, 30, 1, 0, 0);

    // DELETE NODES
    root = deleteNode(root, 10);
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);

}

// FUNCTION: TEST DELETE WITH TWO CHILDREN
static void test_delete_with_two_children(void) {

    // CREATE NODE
    Node *root = NULL;

    // INSERT DATA
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);

    // GET ROOT
    root = deleteNode(root, 20);

    // MAKE ASSERTIONS
    assert_node(root, 30, 2, 1, 0);
    assert_node(root->left, 10, 1, 0, 0);

    // DELETE NODES
    root = deleteNode(root, 10);
    root = deleteNode(root, 30);

}

// FUNCTION: RUN TESTS
void run_tests(void) {

    // RUN ALL TESTS
    test_rr_rotation();
    test_ll_rotation();
    test_lr_rotation();
    test_rl_rotation();
    test_delete_with_two_children();

    // PRINT SUCCESS MESSAGE
    printf("ALL TESTS PASSED!");

}