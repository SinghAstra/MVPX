#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int>& nums,int low,int high){
    if(low>=high){
        return;
    }
    int pivot = nums[low];
    int i = low;
    int j = high;
    while(i<j){
        while(nums[i] <= pivot){
            i++;
        } 
        while(nums[j] > pivot){
            j--;
        } 
        if(i < j){
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[low], nums[j]);
    quickSort(nums, low, j-1);
    quickSort(nums, j+1, high);
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
    vector<int> nums = {2,2,0,1,2,1,0};
    int n = nums.size();
    quickSort(nums,0,n-1);
    printVector(nums);
    return 0;
}