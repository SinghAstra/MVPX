#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;



// Approach 1 : Using Set to Remove Duplicates
// Time Complexity : O(nlogn + n)
// Space Complexity : O(n)
int removeDuplicatesBruteForce(vector<int> & nums){
    set<int> values;
    int n = nums.size();
    for(int i = 0; i < n;i++){
        values.insert(nums[i]);
    }
    int index = 0;
    for(auto it = values.begin();it != values.end();it++){
        nums[index] = *it;
        index++;
    }
    return index;
}


// Approach 2 : Two Pointer
// Time Complexity : O(n)
// Space Complexity : O(1)
int removeDuplicatesTwoPointer(vector<int>& nums){
    int firstPointer = 0;
    int secondPointer = 0;
    int n = nums.size();
    while(secondPointer < n){
        if(nums[firstPointer]!= nums[secondPointer]){
            firstPointer++;
            nums[firstPointer] = nums[secondPointer];
        }
        secondPointer++;
    }
    return firstPointer + 1;
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
    vector<int> nums = {0, 0, 0, 1, 1, 2, 3, 3, 4, 4};
    removeDuplicatesBruteForce(nums); 
    printVector(nums);
    removeDuplicatesTwoPointer(nums);
    printVector(nums);
}