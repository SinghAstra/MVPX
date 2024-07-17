#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

// Approach 1 : Using External Array
// Time Complexity : O(2*n)
// Space Complexity : O(1)
void moveZeroesToTheEndBruteForceApproach(vector<int>& nums){
    // Copy the non zero elements to the external array
    int n = nums.size();
    vector<int> temp;
    for(int i = 0; i < n;i++){
        if(nums[i] != 0){
            temp.push_back(nums[i]);
        }
    }
    // Copy the external array to the front of the original array
    int len = temp.size();
    for(int i = 0; i < len;i++){
        nums[i] = temp[i];
    }
    // Replace the remaining elements of the original array by 0
    for(int i = len;i < n;i++){
        nums[i] = 0;
    }
}

// Approach 2 : Using Two Pointers
// left pointer keeps the track of where the non zero element should be placed
// right pointer scans throughout the array
// For non zero elements swap happens both the left and right pointers are incremented
// For zero elements only the right pointer is incremented and no swap happens
// Time Complexity : O(n)
// Space Complexity : O(1)
void moveZeroesToTheEndTwoPointersApproach(vector<int>& nums){
    int left = 0;
    for(int right = 0; right < nums.size();right++){
        if(nums[right]!=0){
            int temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;
            left++;
        }
    }
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
    vector<int> nums = {0, 1, 3, 0, 0, 6, 7, 8};
    moveZeroesToTheEndTwoPointersApproach(nums);
    printVector(nums);
}