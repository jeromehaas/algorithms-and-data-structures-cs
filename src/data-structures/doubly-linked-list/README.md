# Doubly-Linked List

## Overview

A **doubly-linked list** is a linear collection of nodes where each node holds:

- a value (`data`)
- a pointer to the *next* node
- a pointer to the *previous* node

## Characteristics

- **Bidirectional traversal**: can move forward or backward
- **Dynamic size**: nodes allocated/deallocated at runtime
- **O(1) insert/remove** at either end (given the node)

## Operations & Complexity

| Operation       | Time Complexity |
|-----------------|-----------------|
| **create_list** | O(1)            |
| **append**      | O(1)            |
| **printList**   | O(n)            |
| **free_list**   | O(n)            |

## When to Use

- You need fast insertions/removals at both ends
- You need to traverse both forward and backward
- Memory cost (extra pointer per node) is acceptable
