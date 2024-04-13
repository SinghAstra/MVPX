## Array vs Linked List

**Arrays**

- Contiguous block of memory.
- Fixed size, typically allocated at compile time.
- Random access to elements using indices, O(1) time complexity.

**Linked List**

- Elements are stored in nodes, each containing a value and a pointer/reference to the next node.
- Dynamic size, memory can be allocated and deAllocated as needed.
- No random access, traversal from the head node to the desired node is required, O(n) time complexity.

## Usage of Linked List

- Implementation of Stack and Queue data structure.
- Text editors often use linked lists to implement undo/redo functionality, where each action is stored as a node in a linked list.
- Linked lists can be used in web browsers to manage the navigation in tabs.
- Linked lists can be used to create playlists, where each song is represented as a node in the list.

## Pointers

- Pointers are used to store the address of another variable, allowing indirect access to that variable's value.

Example:

```cpp
int x = 5;
int* y = &x; // y contains memory location of x
*y; // will give the value of x
```

## Memory Used By Linked List

- The total memory used by a linked list depends on the number of nodes in the list and the size of each node.
- The size of each node in a linked list depends on the number of data points each node has and the system architecture (32-bit or 64-bit).
