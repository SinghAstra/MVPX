#include "iostream"
#include "vector" 
#include <algorithm>    
#include <unordered_map> 

using namespace std;

// Approach 1 : Brute Force 
// Time Complexity : O(n^2)
// Space Complexity : O(1)
int singleNumberBruteForce(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        bool found = false;
        for(int j=0;j<nums.size();j++){
            if(i==j){
                continue;
            }
            if(nums[i]==nums[j]){
                found = true;
                break;
            }
        }
        if(!found){
            return nums[i];
        }
    }
    return -1;
}

// Approach 2 : Optimized Approach
// Time Complexity : O(n)
// Space Complexity : O(n)
int singleNumberHashMap(vector<int>& nums) {
    unordered_map<int,int> count;
    for(int i=0;i<nums.size();i++){
        count[nums[i]]++;
    }
    for(auto& it:count){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}

// Approach 3 : Most Optimized Approach : XOR Properties
// Time Complexity : O(n)
// Space Complexity : O(1)
int singleNumberXOR(vector<int>& nums){
    int res = nums[0];
    for(int i=1;i<nums.size();i++){
        res ^= nums[i];
    }
    return res;
}
int main(){
    vector<int> nums = {4,1,2,1,2};
    int ans = singleNumberBruteForce(nums);
    cout << "Single Number: " << ans << endl;
    ans = singleNumberHashMap(nums);
    cout << "Single Number: " << ans << endl;
    ans = singleNumberXOR(nums);
    cout << "Single Number: " << ans << endl;
    return 0;
}