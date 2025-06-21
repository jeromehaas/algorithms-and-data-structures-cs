# Selection Sort

## Overview

Selection Sort divides the array into a sorted and unsorted region. It repeatedly selects the smallest element from the
unsorted region and swaps it into its correct position in the sorted region.

## Complexity

| Case    | Time  | Space |
|---------|-------|-------|
| Best    | O(n²) | O(1)  |
| Average | O(n²) | O(1)  |
| Worst   | O(n²) | O(1)  |

*Not adaptive: always Θ(n²) comparisons.*

## When to Use

- Small arrays.
- Memory-constrained environments (constant extra space).
- Educational purposes.