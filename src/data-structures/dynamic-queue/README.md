# Dynamic Queue

## Overview

A **dynamic queue** is a FIFO (first-in, first-out) collection where items are enqueued at the back and dequeued from
the front. This implementation uses a singly-linked list under the hood.

## Characteristics

- **Dynamic size**: grows and shrinks as you enqueue/dequeue
- **O(1) enqueue & dequeue** (amortized, since we traverse only when enqueuing)
- **Peek** front in O(1)

## Operations & Complexity

| Operation           | Time Complexity |
|---------------------|-----------------|
| **createQueue**     | O(1)            |
| **isEmpty**         | O(1)            |
| **enqueue**         | O(n)¹           |
| **dequeue**         | O(1)            |
| **peek**            | O(1)            |
| **free (implicit)** | O(n)            |

¹ Because we traverse to the tail on each enqueue. If you store a `rear` pointer, you can make it O(1).

## When to Use

- You need a FIFO buffer with unpredictable size
- You’re okay with occasional O(n) enqueues—or you extend it with a tail pointer for constant-time enqueue
- You want simple memory management via `malloc`/`free`
