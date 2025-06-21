# Fixed-Size Stack

## Overview

A **stack** is a LIFO (last-in, first-out) data structure. This implementation uses a fixed-size array (`MAX_SIZE = 3`)
and an integer `top` to track the number of elements.

## Characteristics

- **Array-backed**: contiguous storage
- **Fixed capacity**: cannot exceed `MAX_SIZE`
- **O(1)** for **push**, **pop**, and **peek**

## Operations & Complexity

| Operation  | Time Complexity | Behavior on Error   |
|------------|-----------------|---------------------|
| **create** | O(1)            | —                   |
| **push**   | O(1)            | prints overflow err |
| **peek**   | O(1)            | undefined if empty  |
| **pop**    | O(1)            | returns −1 if empty |

## When to Use

- You need simple LIFO storage with strictly bounded size
- You can tolerate overflow errors being handled via printed messages
