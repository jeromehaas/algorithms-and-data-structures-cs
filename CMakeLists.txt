# VERSION
cmake_minimum_required(VERSION 3.29)

#PROJECT
project(algorithm_collection C)

# STANDARD
set(CMAKE_C_STANDARD 99)

# ARRAY
add_executable(array
        src/data-structures/array/main.c
        src/data-structures/array/tests.c
        src/data-structures/array/array.c
)

# AVL-TREE
add_executable(avl-tree
        src/data-structures/avl-tree/main.c
        src/data-structures/avl-tree/tests.c
        src/data-structures/avl-tree/avl-tree.c
)

# DOUBLY-LINKED-LIST
add_executable(doubly-linked-list
        src/data-structures/doubly-linked-list/main.c
        src/data-structures/doubly-linked-list/tests.c
        src/data-structures/doubly-linked-list/doubly-linked-list.c
)

# DYNAMIC QUEUUE
add_executable(dynamic-queue
        src/data-structures/dynamic-queue/main.c
        src/data-structures/dynamic-queue/tests.c
        src/data-structures/dynamic-queue/dynamic-queue.c
)

# LINKED-LIST
add_executable(linked-list
        src/data-structures/linked-list/main.c
        src/data-structures/linked-list/tests.c
        src/data-structures/linked-list/linked-list.c
)

# LIST
add_executable(list
        src/data-structures/list/main.c
        src/data-structures/list/tests.c
        src/data-structures/list/list.c
)

# STACK
add_executable(stack
        src/data-structures/stack/main.c
        src/data-structures/stack/tests.c
        src/data-structures/stack/stack.c
)

# BUBBLE-SORT
add_executable(bubble-sort
        src/algorithms/bubble-sort/main.c
        src/algorithms/bubble-sort/tests.c
        src/algorithms/bubble-sort/bubble-sort.c
)

# MERGE SORT
add_executable(merge-sort
        src/algorithms/merge-sort/main.c
        src/algorithms/merge-sort/tests.c
        src/algorithms/merge-sort/merge-sort.c
)

# QUICK SORT
add_executable(quick-sort
        src/algorithms/quick-sort/main.c
        src/algorithms/quick-sort/tests.c
        src/algorithms/quick-sort/quick-sort.c
)

# SELECTION SORT
add_executable(selection-sort
        src/algorithms/selection-sort/main.c
        src/algorithms/selection-sort/tests.c
        src/algorithms/selection-sort/selection-sort.c
)

# LINEAR SEARCH
add_executable(linear-search
        src/algorithms/linear-search/main.c
        src/algorithms/linear-search/tests.c
        src/algorithms/linear-search/linear-search.c
)

# BINARY SEARCH
add_executable(binary-search
        src/algorithms/binary-search/main.c
        src/algorithms/binary-search/tests.c
        src/algorithms/binary-search/binary-search.c
)