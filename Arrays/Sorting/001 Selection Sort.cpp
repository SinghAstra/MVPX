#include <bits/stdc++.h>
using namespace std;


// Time Complexity : O(n^2)
// Space Complexity : O(1)
void selectionSort(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(nums[j] < nums[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex!=i){
            swap(nums[i], nums[minIndex]);
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
    selectionSort(nums);
    printVector(nums);
    return 0;
}