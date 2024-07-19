#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


// Time Complexity : O(2^n)
// Space Complexity : O(n)
void backtracking(int index,int target, vector<int>& subSet ,set<vector<int>>& ans, vector<int> nums){
    int len = nums.size();
    if(index >= len){
        sort(subSet.begin(),subSet.end());
        if(target == 0){
            ans.insert(subSet);
        }
        return;
    }
    if(nums[index]>target) {
        backtracking(index+1,target,subSet,ans,nums);
        return ;
    }
    subSet.push_back(nums[index]);
    backtracking(index+1,target-nums[index],subSet,ans,nums);
    subSet.pop_back();
    backtracking(index+1,target,subSet,ans,nums);
}

int main(){
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    vector<int> subSet = {};
    set<vector<int>> ans = {};
    vector<vector<int>> res = {};
    sort(nums.begin(),nums.end());
    backtracking(0,target,subSet,ans,nums);
    cout << "["<<endl;
    for(auto it = ans.begin(); it != ans.end();it++) {
        res.push_back(*it);
    }
    for(int i=0;i<res.size();i++){
        cout<<"[";
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout << "]"<<endl;
    return 0;
}