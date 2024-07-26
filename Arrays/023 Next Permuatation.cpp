#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(3*n)
// Space Complexity : O(1)
void nextPermutation(vector<int>& nums){
    int di = -1;
    int n = nums.size();
    for(int i = n-1; i > 0; i--){
        if(nums[i] > nums[i-1]){
            di = i-1;
            break;
        }
    }
    if(di == -1){
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i = n-1; i>di; i--){
        if(nums[i] > nums[di]){
            swap(nums[i], nums[di]);
            break;
        }
    }
    reverse(nums.begin() + di + 1, nums.end());
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
    vector<int> nums = {1,2,3};
    int n = nums.size();
    nextPermutation(nums);
    printVector(nums);
    return 0;
} 



