# Singly-Linked List

## Overview

A **singly-linked list** is a dynamic, linear collection of nodes where each node holds:

- an integer `data`
- a pointer `next` to the following node (or `NULL` at the end)

## Characteristics

- **Dynamic size**: grows/shrinks at runtime
- **O(1) insertion** at tail if you track the tail; this version is O(n) on `append`
- **O(n) traversal** for most operations

## Operations & Complexity

| Operation       | Time Complexity |
|-----------------|-----------------|
| **create_list** | O(1)            |
| **append**      | O(n)            |
| **printList**   | O(n)            |
| **free_list**   | O(n)            |

## When to Use

- You need a simple, dynamic sequence
- You don’t require random access (that’d be O(n))
- You can tolerate O(n) appends (or you can add a `tail` pointer for O(1) appends)
