#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


// Time Complexity : O(2^n)
// Space Complexity : O(n)
void backtracking(int index,int target, vector<int> subSet ,vector<vector<int>>& ans, vector<int> nums){
    int len = nums.size();
    if(index >= len){
        if(target == 0){
            ans.push_back(subSet);
        }
        return;
    }
    if(target-nums[index]<0){
        backtracking(index+1,target,subSet,ans,nums);
        return ;
    }
    subSet.push_back(nums[index]);
    backtracking(index,target-nums[index],subSet,ans,nums);
    subSet.pop_back();
    backtracking(index+1,target,subSet,ans,nums);
}

int main(){
    vector<int> nums = {2,3,6,7};
    vector<int> subSet = {};
    vector<vector<int>> ans = {};
    backtracking(0,7,subSet,ans,nums);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}