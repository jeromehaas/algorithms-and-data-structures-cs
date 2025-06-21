# Merge Sort

## Overview

Merge Sort is a divide-and-conquer, comparison-based sorting algorithm. It recursively splits the array into halves,
sorts each half, then merges them back together.

## Implementation Details

- **Divide**: Split array into two halves around midpoint.
- **Conquer**: Recursively sort each half.
- **Merge**: Combine two sorted halves in linear time using temporary buffers.

## Complexity

| Case    | Time       | Space |
|---------|------------|-------|
| Best    | O(n log n) | O(n)  |
| Average | O(n log n) | O(n)  |
| Worst   | O(n log n) | O(n)  |

## When to Use

- Stable sort required.
- Large datasets where worst-case O(n log n) is needed.
- Parallelizable (each half can sort independently).
