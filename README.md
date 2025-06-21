# Data Structures & Algorithms
This repository contains clean, self-testing C implementations of the most common data structures and algorithms. It’s designed to help you prepare for your HFIE exam by coding each topic from scratch, complete with unit tests.

---

- **data-structures/**: Dynamic array, singly & doubly linked lists, stack, queue, AVL tree.
- **algorithms/**: Sorting (bubble, selection, merge, quick) and searching (linear, binary).
- Each module is self-contained:
    - `*.c` / `*.h` — implementation & interface
    - `tests.c`      — unit tests via `assert()`
    - `main.c`       — runs `run_tests()`
    - `README.md`    — overview, complexity, build instructions.

---

## Contents

### Data Structures
| Module                  | Description                             |
|-------------------------|-----------------------------------------|
| Dynamic Array           | Resizable int array (append, insert…)   |
| Singly-Linked List      | Forward-only list with prepend/append   |
| Doubly-Linked List      | Bi-directional list with insert/delete  |
| Stack                   | Fixed-capacity LIFO array               |
| Queue                   | Dynamic FIFO via linked list            |
| AVL-Tree                | Self-balancing BST with rotations       |

### Algorithms
| Module         | Description                                    |
|----------------|------------------------------------------------|
| Bubble Sort    | Adaptive O(n²) sort with early-exit flag       |
| Selection Sort | In-place O(n²) sort by selecting minima        |
| Merge Sort     | Divide & conquer O(n log n) stable sort        |
| Quick Sort     | In-place divide & conquer O(n log n) average   |
| Linear Search  | O(n) scan for value in array                  |
| Binary Search  | O(log n) search in sorted array               |

---

## Contributing

- Feel free to add more data structures (e.g., hash tables, heaps) or algorithms (e.g., Dijkstra, graph traversals).
- Maintain the pattern:
    1. `*.c` / `*.h`
    2. `tests.c` with `assert`
    3. `main.c` running `run_tests()`
    4. `README.md` with overview, complexity, build steps
---
