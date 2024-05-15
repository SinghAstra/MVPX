#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;



void backtracking(int index, vector<int> sub, vector<vector<int>>& ans, vector<int> nums){
    int len = nums.size();
    if(index >= len){
        sort(sub.begin(),sub.end());
        ans.push_back(sub);
        return ;
    }
    sub.push_back(nums[index]);
    backtracking(index+1,sub,ans,nums);
    sub.pop_back();
    backtracking(index+1,sub,ans,nums);
}

// Method 1 : Brute Force
// Time Complexity : O(n*2^n + KLog(k)*2^n)
// Generating all the subset : O(2^n) 
// Sorting a subset : O(kLog(k)) 
// Inserting elements into the power Set : O(nLog(n)) : O(2^nLog(2^n)) : O(n*2^n)
// Space Complexity : O(n) + O(2*n)
// Recursive Stack : O(n)
// Power Set : O(2^n)

void subsetsWithDupBruteForce(){
    vector<int> nums = {1,2,2};
    vector<int> sub = {};
    vector<vector<int>> ans = {};
    set<vector<int>> powerSet = {};
    vector<vector<int>> powerVector = {};
    backtracking(0,sub,ans,nums);
    int len = ans.size();
    for(int i = 0; i < len; i++){
        powerSet.insert(ans[i]);
    }
    for(auto it = powerSet.begin(); it != powerSet.end(); it++){
        powerVector.push_back(*it);
    }
}
void backtrackingOptimal(int index, vector<int> sub, vector<vector<int>>& ans, vector<int> nums){
    int len = nums.size();
    if(index >= len){
        sort(sub.begin(),sub.end());
        auto it = find(ans.begin(),ans.end(),sub);
        if(it != ans.end()){
        ans.push_back(sub);
        }
        return ;
    }
    sub.push_back(nums[index]);
    backtrackingOptimal(index+1,sub,ans,nums);
    sub.pop_back();
    backtrackingOptimal(index+1,sub,ans,nums);
}

// Method 1 : Brute Force
// Time Complexity : O(n*2^n + KLog(k)*2^n)
// Generating all the subset : O(2^n) 
// Sorting a subset : O(kLog(k)) 
// Inserting elements into the power Set : O(nLog(n)) : O(2^nLog(2^n)) : O(n*2^n)
// Space Complexity : O(n) + O(2*n)
// Recursive Stack : O(n)
// Power Set : O(2^n)

void subsetsWithDupOptimal(){
    vector<int> nums = {1,2,2};
    vector<int> sub = {};
    vector<vector<int>> ans = {};
    set<vector<int>> powerSet = {};
    vector<vector<int>> powerVector = {};
    backtrackingOptimal(0,sub,ans,nums);
    int len = ans.size();
    for(int i = 0; i < len; i++){
        powerSet.insert(ans[i]);
    }
    for(auto it = powerSet.begin(); it != powerSet.end(); it++){
        powerVector.push_back(*it);
    }
}

int main(){
    return 0;
}