#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;


// Time Complexity : O(n)
// Space Complexity : O(1)
int maximumConsecutiveOnes(vector<int>& nums) {
    int maxConsOnes = 0;
    int currentConsOnes = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0){
            if(currentConsOnes > maxConsOnes) {
                maxConsOnes = currentConsOnes;
            }
            currentConsOnes = 0;
        }else{
            currentConsOnes++;
        }
    }
    return max(currentConsOnes,maxConsOnes);
}

int main(){
    vector<int> nums = {1, 0, 1, 1, 1, 0, 1, 1};
    int number = maximumConsecutiveOnes(nums);
    cout << "Maximum Consecutive Ones: " << number << endl;
}