#include "iostream"
#include "vector" 
#include <algorithm>    
#include <unordered_map> 

using namespace std;

// Approach : Sliding Window
// Time Complexity : O(n^2)
// Space Complexity : O(1)
int subArraySum(vector<int>& nums, int k) {
    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        int currentSum = 0;
        for(int j = i; j < nums.size(); j++) {
            currentSum += nums[j];
            if(currentSum == k) {
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> nums = {1,1,1};
    int k = 2;
    int ans = subArraySum(nums,2);
    cout << ans << endl;
    return 0;
}