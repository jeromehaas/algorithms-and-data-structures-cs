# Dynamic Array

## Overview

A **dynamic array** is a resizable, contiguous block of memory for storing elements of the same type. It grows
automatically when capacity is reached.

## Characteristics

- **Contiguous storage**: Elements stored in a single block ⇒ good cache locality.
- **Resizable**: Starts at a small capacity (here 4), doubles when full.
- **Indexable**: Constant‐time random access.

## Operations & Complexity

| Operation     | Average Case   | Worst Case    |
|---------------|----------------|---------------|
| **create**    | O(1)           | —             |
| **append**    | Amortized O(1) | O(n) (resize) |
| **insert**    | O(n)           | O(n)          |
| **remove_at** | O(n)           | O(n)          |
| **get / set** | O(1)           | O(1)          |
| **free**      | O(1)           | —             |

## When to Use

- You need an array‐like container but size isn’t known at compile time.
- Frequent random reads/writes, occasional inserts/removals.
- When amortized append performance is acceptable.
