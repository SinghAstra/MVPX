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

void reverse(vector<int>& nums,int start,int end){
    int first = start;
    int second = end;
    while(first<second){
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
        first++;
        second--;
    }
}


// Approach 1: Brute Force : Array Rotation Using Auxiliary Space
// Time Complexity : O(n+k)
// Space Complexity : O(k)
void rotateBruteForce(vector<int>& nums, int k) {
    vector<int> temp;
    int len = nums.size();
    k = k%len;
    for(int i = len-k; i < len; i++){
        temp.push_back(nums[i]);
    }
    for(int i = len-k-1; i >=0; i--){
        nums[i+k] = nums[i];
    }
    for(int i = 0; i < k; i++){
        nums[i] = temp[i];
    }
}

// Approach 2 : Optimal Approach : Reversal Algorithm for Array Rotation
// Time Complexity : O(n)
// Space Complexity : O(1)
void rotate(vector<int>& nums, int k){
    int len = nums.size();
    k = k%len;
    reverse(nums,0,len-k-1);
    reverse(nums,len-k,len-1);
    reverse(nums,0,len-1);
}
int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
    printVector(nums);
    return 0;
}