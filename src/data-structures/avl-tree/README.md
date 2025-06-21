# AVL Tree

## Overview

An **AVL tree** is a self-balancing binary search tree that maintains, for every node, the property  
by performing rotations on insertion and deletion.

## Characteristics

- **Height-balanced**: every node’s subtrees differ in height by at most 1
- **Binary Search Tree**: left subtree keys < node.key < right subtree keys
- **Rotations**: LL, RR, LR, RL to restore balance

## Operations & Complexity

| Operation    | Average Case | Worst Case      |
|--------------|--------------|-----------------|
| **insert**   | O(log n)     | O(log n) (rot.) |
| **delete**   | O(log n)     | O(log n) (rot.) |
| **search**   | O(log n)     | O(log n)        |
| **preOrder** | O(n)         | O(n)            |

## When to Use

- Need guaranteed O(log n) inserts/deletes/queries
- Workloads with frequent insertions and deletions
- Cases where unbalanced BST could degrade to O(n)
