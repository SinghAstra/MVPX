#include <bits/stdc++.h>
using namespace std;


// Time Complexity : O(n^2)
// Space Complexity : O(1)
void insertionSort(vector<int>& nums){
    int n = nums.size();
    for(int i = 1; i < n; i++){
        int currentIndex = i;
        while(currentIndex > 0 && nums[currentIndex - 1] > nums[currentIndex]){
            swap(nums[currentIndex - 1], nums[currentIndex]);
            currentIndex--;
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
    insertionSort(nums);
    printVector(nums);
    return 0;
}