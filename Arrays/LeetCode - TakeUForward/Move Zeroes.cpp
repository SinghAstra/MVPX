#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;


void printVector(vector<int> nums){
    int len = nums.size();
    cout << "[";
    for(int i = 0; i < len;i++){
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}

// Two-Pointer Technique for Moving Zeros to End
// Time Complexity : O(n)
// Space Complexity : O(1)
void moveZeroes(vector<int>& nums) {
    int count = 0;
    int len = nums.size();
    int pointer = 0;
    for(int i = 0; i < len; i++){
        if(nums[i]== 0){
            count++; 
        }else{
            nums[pointer] = nums[i];
            pointer++;
        }
    }   
    int index = len - 1;
    while(count>0){
        nums[index] = 0;
        index--;
        count--;
    }
}

int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    return 0;
}