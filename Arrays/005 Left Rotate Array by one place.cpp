#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

// Approach : One Pass Approach
// Time Complexity : O(n)
// Space Complexity : O(1)
void leftRotateArrayByOnePlace(vector<int>& nums){
    int firstElement = nums[0];
    int n = nums.size();
    for(int i = 1; i < n; i++){
        nums[i-1] = nums[i];
    }
    nums[n-1] = firstElement;
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
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    leftRotateArrayByOnePlace(nums);
    printVector(nums);
}