# Advantages of Hashing Using Map Over Array Hashing

- **Efficient Lookups**:

  - Maps offer constant time complexity (O(1)) for lookups, insertions, and deletions, providing faster operations compared to array-based approaches which may require O(n) time.

- **Dynamic Resizing**:
  - Maps can dynamically resize to accommodate more elements, whereas array-based hashing might require manual resizing and rehashing.

# Time Complexity of Ordered and Unordered Maps

## Ordered Map (std::map in C++)

- **Best Case**:
  - Lookup: O(log n)
  - Insertion: O(log n)
  - Deletion: O(log n)
- **Average Case**:
  - Lookup: O(log n)
  - Insertion: O(log n)
  - Deletion: O(log n)
- **Worst Case**:
  - Lookup: O(log n)
  - Insertion: O(log n)
  - Deletion: O(log n)

## Unordered Map (std::unordered_map in C++)

- **Best Case**:
  - Lookup: O(1)
  - Insertion: O(1)
  - Deletion: O(1)
- **Average Case**:
  - Lookup: O(1)
  - Insertion: O(1)
  - Deletion: O(1)
- **Worst Case**:
  - Lookup: O(n)
  - Insertion: O(n)
  - Deletion: O(n)
  - **Reason**: The worst case for unordered maps occurs due to internal collisions. When many keys hash to the same bucket, the operations degrade to linear time complexity.

# Implementation of Hashing Methods

- Division method
- Folding method
- Mid square method
