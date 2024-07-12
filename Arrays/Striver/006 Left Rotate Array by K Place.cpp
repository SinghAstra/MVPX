#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;


// Approach 1 : Left Rotate the Array one Element at a time
// Time Complexity : O(n*k)
// Space Complexity : O(1)
void leftRotateArrayByKPlaceBruteForce(vector<int>& nums, int k ){
    int n = nums.size();
    k = k % n;
    for (int count = 0; count < k; count++){
        int temp = nums[0];
        for (int i = 1; i < n; i++){
            nums[i-1] = nums[i];
        }
        nums[n-1] = temp;
    }
}


// Approach 2 : Use Extra Array 
// Time Complexity : O(n+k)
// Ṣpace Complexity : O(k)
void leftRotateArrayByKPlaceBetterApproach(vector<int>& nums, int k){
    int n = nums.size();
    k = k % n;

    // Store the first k elements in extra array
    vector<int> temp;
    for(int i = 0; i < k; i++){
        temp.push_back(nums[i]);
    }

    // Shift the remaining elements to the left by K places
    for(int i = k; i < n; i++){
        nums[i-k] = nums[i];
    }

    // Copy the elements from extra array to the original array
    for(int i = n-k; i < n ; i++){
        nums[i] = temp[i-n+k];
    }
}


// Reversing the array using two pointers
void reverse(vector<int>& nums ,int startIndex, int count){
    int first = startIndex;
    int second = startIndex + count - 1;
    while(first < second){
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
        first++;
        second--;
    }
}

// Approach 3 : Three Reverse Approach
// Time Complexity : O(2*n)
// Space Complexity : O(1)
void leftRotateArrayByKPlaceOptimalApproach(vector<int>& nums, int k){
    int n = nums.size();
    k = k % n;
    reverse(nums,0,k);
    reverse(nums,k,n-k);
    reverse(nums,0,n);
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
    leftRotateArrayByKPlaceBruteForce(nums,3);
    leftRotateArrayByKPlaceBetterApproach(nums,3);
    leftRotateArrayByKPlaceOptimalApproach(nums,3);
    printVector(nums);
}