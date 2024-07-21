#include <bits/stdc++.h>
using namespace std;


// Time Complexity : O(n^2)
// Space Complexity : O(1)
void bubbleSort(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(nums[j+1] < nums[j]){
                swap(nums[j+1], nums[j]);
            }
        }
    }
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
    vector<int> nums = {5, 2, 4, 6, 1, 3};
    bubbleSort(nums);
    printVector(nums);
    return 0;
}