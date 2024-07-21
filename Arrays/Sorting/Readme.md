## Selection Sort

- **Selection Sort** works by repeatedly finding the minimum (or maximum) element from the unsorted portion of the array and swapping it with the first unsorted element.
- **Time Complexity:** O(n^2)
- **Space Complexity:**O(1)

## Bubble Sort

- **Bubble Sort**

  - It works by comparing adjacent elements, and swapping them if they are in the wrong order.
  - Traverse the array from the start to the end.
  - Compare each pair of adjacent elements and swap them if necessary.
  - After each pass, the largest unsorted element "bubbles up" to its correct position.
  - Repeat the process for the remaining unsorted portion of the array until no swaps are needed.

- **Time Complexity:** O(n^2)
- **Space Complexity:** O(1)

## Insertion Sort

- **Insertion Sort** works by building a sorted portion of the array, one element at a time by repeatedly picking the next element and inserting it into the correct position within the sorted portion.

- **Steps:**

  1. Start with the second element of the array (assume the first element is a sorted portion).
  2. Compare this element with the elements in the sorted portion (to its left).
  3. Shift all elements in the sorted portion that are greater than the current element to the right.
  4. Insert the current element into its correct position.
  5. Repeat the process for each subsequent element until the entire array is sorted.

- **Time Complexity:** O(n^2)
- **Space Complexity:** O(1)

## Merge Sort

- **Merge Sort** is a divide-and-conquer sorting algorithm.
- It works by recursively dividing the array into two halves, sorting each half, and then merging the sorted halves to produce a sorted array.

- **Steps:**

  1. Divide the array into two halves.
  2. Recursively sort each half.
  3. Merge the two sorted halves to produce a single sorted array.
  4. Repeat the process until the entire array is sorted.

- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n) (due to the auxiliary space needed for the temporary arrays during the merge process)
