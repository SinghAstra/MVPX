#include <bits/stdc++.h>
using namespace std;


void merge(vector<int>& nums,int low, int mid, int high){
    vector<int> temp;
    int first = low;
    int second = mid + 1;
    while(first<=mid&&second<=high){
        if(nums[first] <= nums[second]){
            temp.push_back(nums[first]);
            first++;
        }else{
            temp.push_back(nums[second]);
            second++;
        }
    }
    while(first<=mid){
        temp.push_back(nums[first]);
        first++;
    }
    while(second<=high){
        temp.push_back(nums[second]);
        second++;
    }
    for(int i = low; i <= high; i++){
        nums[i] = temp[i-low];
    }
}


// Time Complexity : O(nlogn)
// Space Complexity : O(n)
void mergeSort(vector<int>& nums,int low,int high){
    if(low>=high){
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(nums,low,mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);
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
    int n = nums.size();
    mergeSort(nums,0,n-1);
    printVector(nums);
    return 0;
}