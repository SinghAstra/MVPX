#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    // Approach 1: Brute Force 
    // Time Complexity : O(n^2)
    // Space Complexity : O(1)
    int maxSum = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        int sum = 0;
        for(int j = i; j < nums.size(); j++){
            sum += nums[j];
            if(sum > maxSum){
                maxSum = sum;
            }
        }
    }
    cout << "maxSum : "<<maxSum << endl;

    // Approach 2 : Kadane Algorithm
    // TIme Complexity : O(n)
    int maxSum = nums[0];
    int currentSum = nums[0];
        for(int i=1;i<nums.size();i++){
            currentSum = max(nums[i],nums[i]+currentSum);
            maxSum = max(currentSum,maxSum);
        }
    return maxSum;  
}