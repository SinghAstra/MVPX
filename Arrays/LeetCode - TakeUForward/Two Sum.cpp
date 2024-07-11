#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <unordered_map> 

using namespace std;

void printVector(vector<int> nums){
    int len = nums.size();
    cout << "[";
    for(int i = 0; i < len; i++){
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}

// Approach 1 : Brute Force : Generate all two Sum
// Time Complexity : O(N^2)
// Space Complexity : O(1)
vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    int len = nums.size();
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(nums[i] + nums[j] == target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

// Approach 2 : Better Approach : Using Hashmap
// Time Complexity : O(N)
// Space Complexity : O(N)
vector<int> twoSumHashMap(vector<int>& nums, int target) {
    int len = nums.size();
    unordered_map<int,int> map;
    for(int i = 0; i < len; i++){
        if(map.find(target - nums[i]) != map.end()){
            return {map[target - nums[i]],i};
        }
        map[nums[i]] = i;
    }    
    return {-1,-1};
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = twoSumHashMap(nums, target);
    printVector(result);
}