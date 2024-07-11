#include "iostream"
#include "vector" 
#include <algorithm>    
#include <unordered_map> 

using namespace std;

void printTwoDimensionalVector(vector<vector<int>> nums){
    for(int i=0; i<nums.size();i++){
        cout << "[";
        for(int j=0; j<nums[i].size();j++){
            cout << nums[i][j] <<" ";
        }
        cout << "]"<<endl;
        }
}

// Approach 1 : Brute Force Method
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)
vector<vector<int>> formSubArrayBruteForce(vector<int> nums){
    int len = nums.size();
    vector<vector<int>> result;
    for(int i = 0; i < len;i++){
        for(int j = i; j < len;j++){
            int start = i;
            int end = j;
            vector<int> subArray;
            while(start <= end){
                subArray.push_back(nums[start]);
                start++;
            }
            result.push_back(subArray);
        }
    }
    return result;
}

// Approach 2 : Sliding Window
// Time Complexity : O(n^2)
// Space Complexity : O(n^2)
vector<vector<int>> formSubArraySlidingWindow(vector<int> nums){
    int len = nums.size();
    vector<vector<int>> result;
    for(int i = 0; i < len;i++){
        vector<int> subArray;
        for(int j = i; j < len;j++){
            subArray.push_back(nums[j]);
            result.push_back(subArray);
        }
    }
    return result;
}

int main(){
    vector<int> nums = {10,20,30,40,50,60};
    vector<vector<int>> result = formSubArraySlidingWindow(nums);
    printTwoDimensionalVector(result); 
    return 0;
}