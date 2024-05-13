#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


// Bubble Sort Algorithm
//
// This function sorts a vector of integers using the bubble sort algorithm.
// It repeatedly iterates through the vector, compares adjacent elements,
// and swaps them if they are in the wrong order. The process stops early
// if no swaps occur in a pass, indicating the list is already sorted.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1) - Uses constant extra space for temporary variables.

vector<int> bubbleSort(vector<int> nums){
    int len = nums.size();
    for(int i = 0; i < len-1; i++){// Step 1: Outer loop (number of passes)
        int swapped = 0;// Step 3: No swaps flag (optimization)
        for(int j = 0; j < len-i-1; j++){// Step 2: Inner loop (comparisons and swaps)
            if(nums[j]>nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                swapped = 1; // Step 4: Set swapped flag if a swap occurs
            }
        }
    if (swapped == 0) { // Step 5: Check if no swaps in a pass (early termination)
      break; // List is sorted, exit outer loop
    }
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
    nums = bubbleSort(nums);
    printVector(nums);
}