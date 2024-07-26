#include<bits/stdc++.h>
using namespace std;


// Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
// After doing so, return the array.


// Time Complexity : O(n^2)
// Space Complexity : O(1)
void replaceElementsBruteForce(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n;i++){
        int maxRight = INT_MIN;
        for(int j = i+1; j < n; j++){
            if(nums[j] > maxRight){
                maxRight = nums[j];
            }
        }
        nums[i] = maxRight;
    }
    nums[n-1] = -1;
}


// Time Complexity : O(n)
// Space Complexity : O(1)
void replaceElements(vector<int>& nums){
    int n = nums.size();
    int max = -1;
    for(int i = n-1;i>=0;i--){
        int temp = nums[i];
        nums[i] = max;
        if(temp > max){
            max = temp;
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
    vector<int> nums = {17,18,5,4,6,1};
    int n = nums.size();
    replaceElements(nums);
    printVector(nums);
    return 0;
} 



