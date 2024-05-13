#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


void printVector(vector<int> nums){
    cout << "Elements in vector are : ";
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void quickSort(vector<int>& nums, int low, int high){
    if(low>=high){
        return;
    }
    int pivot = nums[low];
    int start = low;
    int end = high;
    while(start<end){
        while(nums[start]<=pivot&&start<=high-1){
            start++;
        }
        while(nums[end]>pivot&&end>=low+1){
            end--;
        }
        if(start<end){
            swap(nums[start],nums[end]);
        }
    }
    swap(nums[low],nums[end]);
    quickSort(nums,low,end-1);
    quickSort(nums,end+1,high);
}

int main(){
    vector<int> nums = {5,2,3,1};
    quickSort(nums,0,nums.size()-1);
    printVector(nums);
}