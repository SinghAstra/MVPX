## Selection Sort

- **Algorithm Overview:**

  - **Selection Sort** is a simple comparison-based sorting algorithm.
  - It works by repeatedly finding the minimum (or maximum) element from the unsorted portion of the array and swapping it with the first unsorted element.

- **Steps:**

  1. Start with the first element of the array.
  2. Find the smallest element in the unsorted portion of the array.
  3. Swap this smallest element with the first unsorted element.
  4. Move the boundary of the sorted portion one element to the right.
  5. Repeat the process for the remaining unsorted portion of the array until the entire array is sorted.

- **Time Complexity:**

  - **Best Case:** O(n^2)
  - **Average Case:** O(n^2)
  - **Worst Case:** O(n^2)

- **Space Complexity:**
  - **O(1)** (In-place sorting)
  - _Note:_ Selection Sort does not require additional space beyond the input array.
