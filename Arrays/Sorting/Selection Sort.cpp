#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;

// Selection Sort Algorithm
//
// This function sorts a vector of integers using the selection sort algorithm.
// It iterates through the vector, finding the minimum element in the unsorted
// portion and swapping it with the first element of that unsorted portion in
// each pass. This process continues until the entire vector is sorted.
//
// Time Complexity: O(n^2) - Nested loops for iterating through the vector.
// Space Complexity: O(1) - Uses constant extra space for temporary variables.

vector<int> selectionSort(vector<int> nums){
    int len = nums.size();
    for(int i = 0; i < len;i++){
        // Find the index of the minimum element in the unsorted portion
        int currentMin = nums[i];
        int currentMinIndex = -1;
        for(int j = i+1; j <len; j++){
            if(nums[j] < currentMin){
                currentMin = nums[j];
                currentMinIndex = j;
            }
        }
        // Swap the minimum element with the first element of the unsorted part
        if(currentMinIndex!= -1){
            int temp = nums[i];
            nums[i] = nums[currentMinIndex];
            nums[currentMinIndex] = temp;
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
    nums = selectionSort(nums);
    printVector(nums);
}