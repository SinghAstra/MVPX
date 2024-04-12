#include "iostream"
#include "vector" 
#include <algorithm>    
#include <unordered_map> 

using namespace std;

int main(){
    // Approach 1 : Brute Force 
    // Time Complexity : O(n^2)
    // Space Complexity : O(1)
    vector<int> nums = {4,1,2,1,2};
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
            cout<<"Single Number : "<<nums[i]<<endl;
        }
    }

    // Approach 2 : Optimized Approach
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    unordered_map<int,int> count;
    for(int i=0;i<nums.size();i++){
        count[nums[i]]++;
    }
    for(auto& it:count){
        if(it.second == 1){
            cout << "Single Number: " << it.first << endl;
        }
    }

    // Approach 3 : Most Optimized Approach
    // Time Complexity : O(n)
    // Space Complexity : O(1)
    int res = nums[0];
    for(int i=1;i<nums.size();i++){
        res ^= nums[i];
    }
    cout<<"Single Number : "<<res<<endl;
    return -1;
}