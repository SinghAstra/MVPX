#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n^3)
// Space Complexity : O(1)
int subArraySumBruteForce(vector<int>& nums, int k){
    int n = nums.size();
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int m=i; m<=j; m++){
                sum += nums[m];
            }
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}


// Time Complexity : O(n^2)
// Space Complexity : O(1)
int subArraySumBetterApproach(vector<int>& nums,int k){
    int n = nums.size();
    int count = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += nums[j];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

// Time Complexity : O(n)
// Space Complexity : O(n)
 int subArraySum(vector<int>& nums, int k) {
    int sum = 0;
    int count = 0;
    int n = nums.size();
    unordered_map<int, int> prefixSum;
    for(int i = 0; i < n; i++){
        prefixSum[sum]++;
        sum += nums[i];
        auto it = prefixSum.find(sum-k);
        if(it!= prefixSum.end()){
            count += prefixSum[sum-k];
        }
    }
    return count;
}

int main(){
    vector<int> nums = {1,2,3};
    int k = 3;
    int count = subArraySum(nums,k);
    cout << "Number of subArrays with sum " << k << ": " << count << endl;
    return 0;
}