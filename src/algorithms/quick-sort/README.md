# Quick Sort

## Overview

Quick Sort is a divide-and-conquer sorting algorithm. It selects a **pivot** element, partitions the array so that
elements ≤ pivot come before and > pivot come after, then recursively sorts the partitions.

## Implementation

1. **Partition**: choose the last element as pivot, arrange elements around it.
2. **Recurse**: sort the left and right subarrays.

```c
static int partition(int array[], int low, int high) { ... }
void quickSort(int array[], int low, int high) { ... }
```

## Complexity

| Case    | Time       | Space    |
|---------|------------|----------|
| Best    | O(n log n) | O(log n) |
| Average | O(n log n) | O(log n) |
| Worst   | O(n²)      | O(n)     |

*Worst case occurs when pivot choices are poor (e.g., already sorted input).*

## When to Use

- Large arrays where average-case performance matters
- In-place sorting with good cache behavior
- When you can tolerate O(n²) worst-case or implement pivot optimizations
