#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxOnes = 0;
    int len = nums.size();
    int currentOnes = 0;
    for(int i = 0; i < len; i++){
        if(nums[i] == 0){
            if(currentOnes>maxOnes){
                maxOnes = currentOnes;
            }
            currentOnes = 0;
        }else{
            currentOnes++;
        }
    }  
    maxOnes = max(maxOnes,currentOnes);
    return maxOnes;
}

int main(){
    vector<int> nums = {1,1,0,1,1,1};
    int ans = findMaxConsecutiveOnes(nums);
    cout << "ans : "<< ans << endl;
    return 0;
}