#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;


void printVector(vector<int> nums){
    int len = nums.size();
    cout << "[";
    for(int i = 0; i < len;i++){
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}


// Approach 1 : Brute Force Approach : Removing Duplicates and Sorting Using a Set
// Time Complexity : O(n log n) : insertion into the set takes logarithmic time
// Space Complexity : O(n) : set can grow linearly
int removeDuplicatesBruteForce(vector<int>& nums) {
    int n = nums.size();
    set<int> unique;

    for(int i = 0; i <n; i++){
        unique.insert(nums[i]);
    }
    
    int index = 0;
    for(auto it = unique.begin(); it != unique.end();it++) {
        nums[index] = *it;
        index++;
    }
      
    return index;
}

// Approach 2 : Optimal Approach : Two-Pointer Technique for Removing Duplicates in a Sorted Array
// Time Complexity : O(n)
// Space Complexity : O(1)
int removeDuplicates(vector<int>& nums){
    int pointer = 0;
    int currentElement = nums[0];
    int n = nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i]!= currentElement){
            pointer++;
            currentElement = nums[i];
            nums[pointer] = nums[i];
        }
    }
    return pointer + 1;
}





int main(){
    vector<int> nums = {1,1,2};
    int k = removeDuplicatesBruteForce(nums); 
    printVector(nums);
    cout << k << endl;    
    return 0;
}