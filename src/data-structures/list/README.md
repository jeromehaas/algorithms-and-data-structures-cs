# Doubly-Linked List

## Overview

This is a doubly‐linked list supporting:

- **add** (prepend)
- **append**
- **insert** at arbitrary index
- **delete** at arbitrary index
- **traverse** for debugging
- **free_list**

## Characteristics

- Each node has `data`, `next`, and `previous` pointers.
- List stores `head`, `tail`, and `size`.
- Prepend/appends adjust both ends in O(1).
- Arbitrary insert/delete require O(n) scan.

## Operations & Complexity

| Operation       | Time Complexity |
|-----------------|-----------------|
| **create_list** | O(1)            |
| **add**         | O(1)            |
| **append**      | O(1)            |
| **insert**      | O(n)            |
| **delete**      | O(n)            |
| **traverse**    | O(n)            |
| **free_list**   | O(n)            |

## When to Use

- You need constant‐time operations at both ends.
- You need to insert or delete in the middle.
- You can tolerate the extra pointer per node.