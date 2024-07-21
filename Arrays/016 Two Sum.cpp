#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(n^2)
// Space Complexity : O(1)
vector<int> twoSumBruteForce(vector<int>& nums, int target){
    int n = nums.size();
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(nums[i] + nums[j] == target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

// Approach 2 : Using Map
// Time Complexity : O(n)
// Worst Case Time Complexity : O(n^2)
// Space Complexity : O(n)
vector<int> twoSumMap(vector<int> nums,int target){
    unordered_map<int,int> map;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        auto it = map.find(target - nums[i]);
        if(it!= map.end()){
            return {it->second,i};
        }
        map[nums[i]] = i;
    }
    return {-1,-1};
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
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSumMap(nums,target);
    printVector(ans);
}