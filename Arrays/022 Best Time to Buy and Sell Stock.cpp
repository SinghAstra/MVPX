#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(1)
int maxProfit(vector<int>& prices) {
        int currentProfit = 0;
        int maxProfit = 0;
        int currentMin = prices[0];
        int n = prices.size();
        
        for(int i = 1; i < n; i++){
            currentProfit = prices[i] - currentMin;
            maxProfit = max(maxProfit, currentProfit);
            currentMin = min(currentMin, prices[i]);
        }

        return maxProfit;
    }

int main(){
    vector<int> nums = {7,1,5,3,6,4};
    int n = nums.size();
    int ans = maxProfit(nums);
    cout << "Maximum Profit : "<<ans << endl;
    return 0;
}