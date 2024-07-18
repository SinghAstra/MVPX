#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

// Time Complexity : O(n^2)
// Space Complexity : O(1)
int missingNumberBruteForceApproach(vector<int> nums){
    int n = nums.size();
    for(int i = 0; i < n;i++){
        bool isFound = false;
        for(int j = 0; j < n; j++){
            if(nums[j] == i){
                isFound = true;
                break;
            }
        }
        if(!isFound){
            return i;
        }
    }
    return -1;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
int missingNumberOptimizedApproach(vector<int> nums){
    int n = nums.size();
    int expectedSum = n * (n+1) * 0.5;
    int actualSum = 0;
    for(int i = 0; i < n; i++){
        actualSum += nums[i];
    }
    return expectedSum - actualSum;
}

int main(){
    vector<int> nums = {3, 0, 1};
    int number = missingNumberOptimizedApproach(nums);
    cout << "Missing number: " << number << endl;
}