#include<bits/stdc++.h>
using namespace std;



// Approach 1 : Using Quick Sort
// Time Complexity : O(nlogn)
// Space Complexity : O(1)
void quickSort(vector<int>& nums,int low,int high){
    int pivot = nums[low];
    int n = nums.size();
    int f = low;
    int s = high;
    if(low>=high){
        return;
    }
    while(f<s){
        while(nums[f] <= pivot&&f<n)
            f++;
        while(nums[s] > pivot &&s>=0)
            s--;
        if(f < s){
            swap(nums[f], nums[s]);
        }
    }
    swap(nums[low], nums[s]);
    quickSort(nums, low, s-1);
    quickSort(nums, s+1, high);
}


// Approach 2 : Counting Sort
// Time Complexity : O(2*n)
// Space Complexity : O(1) 
void countingSort(vector<int>& nums){
    int n = nums.size();
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < n;i++){
        if(nums[i] == 0)
            count0++;
        else if(nums[i] == 1)
            count1++;
        else
            count2++;
    }
    for(int i = 0; i < count0; i++){
        nums[i] = 0;
    }
    for(int i = count0; i < count0 + count1; i++){
        nums[i] = 1;
    }
    for(int i = count0 + count1; i < n; i++){
        nums[i] = 2;
    }
}


// Approach 3 : Dutch National Flag Algorithm
// Time Complexity : O(n)
// Space Complexity : O(1)
void dutchFlag(vector<int>& nums){
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
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
    vector<int> nums = {2,0,0,1,2,1,1,0,0};
    int n = nums.size();
    dutchFlag(nums);
    printVector(nums);
}