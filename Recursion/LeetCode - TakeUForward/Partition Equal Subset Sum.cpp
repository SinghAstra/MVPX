#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


// Time Complexity : O(2^n)
// Space Complexity : O(n*(2^n))
// Drawback - Exponential Space Complexity - Memory Limit Exceeded - Use DP
bool subSequence(int index, vector<int> sub, vector<int> nums){
    int len = nums.size();
    if(index >= len){
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += nums[i];
        }
        int subSum = 0;
        for(int i = 0; i < sub.size(); i++){
            subSum += sub[i];
        }
        if((subSum*2) == sum){
            cout << "SubSequence : ";
            for(int i = 0; i < sub.size(); i++){
                cout << sub[i] << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    sub.push_back(nums[index]);
    if(subSequence(index+1,sub,nums)){
        return true;
    }else{
        sub.pop_back();
        return subSequence(index+1,sub,nums);
    }
}


bool canPartition(vector<int>& nums) {
    vector<int> sub = {};
    return subSequence(0,sub,nums);
}

int main(){
    vector<int> nums = {1,5,11,5};
    bool isCanPartition = canPartition(nums);
    cout <<"isCanPartition : "<<isCanPartition << endl;
    return 0;
}