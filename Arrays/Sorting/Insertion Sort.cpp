#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;

// Insertion Sort Algorithm
//
// This function sorts a vector of integers using the insertion sort algorithm.
// It iterates through the vector, building a sorted sub-array at the beginning
// and inserting each unsorted element into its correct position within the
// sub-array.
//
// Time Complexity: O(n^2) - Nested loops for iterating and shifting elements.
// Space Complexity: O(1) - Uses constant extra space for temporary variables.

vector<int> insertionSort(vector<int> nums){
    int len = nums.size();
    for(int i = 1; i < len;i++){// Step 1: Loop through unsorted elements (start from 2nd)
        int current = nums[i];// Step 2: Pick current element

        // Step 3: Compare with sorted sub-array and shift elements if needed
        int j = i - 1;
        int j = i-1;
        while (j>=0&&nums[j]>current){
            nums[j+1] = nums[j];
            j--;
        }

        // Step 4: Insert current element at its correct position
        nums[j+1] = current;
    }
    return nums;
}

void printVector(vector<int> nums){
    cout << "Elements in vector are : ";
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
}

int main(){
    vector<int> nums = {23,45,12,34,6,2};
    nums = insertionSort(nums);
    printVector(nums);
}