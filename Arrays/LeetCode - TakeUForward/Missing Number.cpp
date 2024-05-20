#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
    }
    return n*(n+1)/2 - sum;
}

int main(){
    vector<int> nums = {3,0,1};
    int ans = missingNumber(nums);
    cout << ans << endl;
    return 0;
}