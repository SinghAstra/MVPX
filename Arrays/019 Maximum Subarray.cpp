#include<bits/stdc++.h>
using namespace std;



// Approach 1 : Brute Force 
// Time Complexity : O(n^2)
// Space Complexity : O(1)
int maximumSubArrayBruteForce(vector<int> nums){
    int maxSum = INT_MIN;
    int currentSum = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        currentSum = 0;
        for(int j = i; j < n; j++){
            currentSum += nums[j];
            if(currentSum > maxSum){
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}

// Approach 2 : Kadane's Algorithm
// Time Complexity : O(n)
// Space Complexity : O(1)
int maximumSubArrayKadaneAlgorithm(vector<int> nums){
    int maxSum = INT_MIN;
    int currentSum = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(currentSum<0){
            currentSum = 0;
        }
        currentSum += nums[i];
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
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
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int n = nums.size();
    int maxSum = maximumSubArrayKadaneAlgorithm(nums);
    cout <<"Maximum Sum : " << maxSum << endl;
    return 0;
}