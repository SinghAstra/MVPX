#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

 
void rightRotateArrayByOnePlace(vector<int>& nums){
    int n = nums.size();
    int lastElement = nums[n-1];
    for(int i = n-1; i >= 0; i--){
        nums[i] = nums[i-1];
    }
    nums[0] = lastElement;
}

// Approach 1 : Right Rotate Array one element at a time
// Time Complexity : O(n*k)
// Space Complexity : O(1)
void rightRotateArrayByKPlaceBruteForce(vector<int>& nums, int k){
    k = k % nums.size();
    for(int i = 0; i < k; i++){
        rightRotateArrayByOnePlace(nums);
    }
}

// Approach 2 : Using an external array
// Time Complexity : O(n*k)
// Space Complexity : O(1)
void rightRotateArrayByKPlaceBetterApproach(vector<int>& nums,int k){
    int n = nums.size();
    vector<int> temp;
    // Store the last k elements of the array
    for(int i = n-k;i<n;i++){
        temp.push_back(nums[i]);
    }
    // Shift the remaining elements to the right by k places
    for(int i=n-k;i>=0;i--){
        nums[i+k] = nums[i];
    }
    // Copy the elements from the temporary array to the original array
    for(int i=0;i<k;i++){
        nums[i] = temp[i];
    }
}

// Reverse the Array Using Two Pointers
void reverseArray(vector<int>& nums,int start,int count){
    int end = start + count - 1;
    while(start < end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

// Approach 3 : Three Reverse Approach
// Time Complexity : O(n)
// Space Complexity : O(1)
void rightRotateArrayByKPlaceThreeReverseApproach(vector<int>& nums, int k){
    int n = nums.size();
    k = k % n;
    reverseArray(nums, 0, n-k);
    reverseArray(nums, n-k, k);
    reverseArray(nums, 0, n);
}



void printVector(vector<int> nums){
    int n = nums.size();
    cout << "Vector : ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;
    rightRotateArrayByKPlaceBruteForce(nums,k);
    printVector(nums);
    rightRotateArrayByKPlaceBetterApproach(nums,k);
    printVector(nums);
    rightRotateArrayByKPlaceThreeReverseApproach(nums,k);
    printVector(nums);
}