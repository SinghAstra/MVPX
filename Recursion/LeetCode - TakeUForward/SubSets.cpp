#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


// Time Complexity : O(2^n)
// Space Complexity : O(2^n)
void backtracking(int index, vector<int> subSet ,vector<vector<int>>& ans, vector<int> nums){
    int len = nums.size();
    if(index >= len){
        ans.push_back(subSet);
        return;
    }
    subSet.push_back(nums[index]);
    backtracking(index+1,subSet,ans,nums);
    subSet.pop_back();
    backtracking(index+1,subSet,ans,nums);
}

int main(){
    vector<int> nums = {3,1,2};
    vector<int> subSet = {};
    vector<vector<int>> ans = {};
    backtracking(0,subSet,ans,nums);
    return 0;
}