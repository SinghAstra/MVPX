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

// Merge function to combine two sorted sub-arrays in a vector.
void merge(vector<int>& nums,int low,int mid,int high){
    // Create temporary variables to track indices in the sub-arrays.
    int first = low;
    int second = mid+1;

    // Create a temporary vector to store the merged sub-arrays.
    vector<int> temp;

    // Merge elements from both sub-arrays until one is empty.
    while(first<=mid&&second<=high){
        if(nums[first]<nums[second]){
            // Add the smaller element from the first sub-array to temp.
            temp.push_back(nums[first]);
            first++;
        }else{
            // Add the smaller element from the second sub-array to temp.
            temp.push_back(nums[second]);
            second++;
        }
    }

    // Copy remaining elements from the first sub-array (if any).
    while(first<=mid){
        temp.push_back(nums[first]);
        first++;
    }

    // Copy remaining elements from the second sub-array (if any).
    while(second<=high){
        temp.push_back(nums[second]);
        second++;
    }

    // Copy the merged elements from temp back to the original vector.
    for(int i=0;i<temp.size();i++){
        nums[low+i]=temp[i];
    }
}

void mergeSort(vector<int>& nums,int low ,int high){
    if(low>=high){
        return ;
    }
    int mid=(low+high)/2;
    mergeSort(nums,low,mid);
    mergeSort(nums,mid+1,high);
    merge(nums,low,mid,high);
}


int main(){
    vector<int> nums = {23,45,12,34,6,2};
    mergeSort(nums,0,nums.size()-1);
    printVector(nums);
}