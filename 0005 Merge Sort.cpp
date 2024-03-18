#include "iostream"
#include "vector" 
#include <algorithm>      

using namespace std;


void merge(vector<int>& nums, int start,int mid,int end){
    int firstPointer = start;
    int secondPointer = mid+1;
    vector<int> ans;
    while(firstPointer<=mid&&secondPointer<=end){
        if(nums[firstPointer]<nums[secondPointer]){
            ans.push_back(nums[firstPointer]);
            firstPointer++;
        }
        else{
            ans.push_back(nums[secondPointer]);
            secondPointer++;
        }
    }
    if(firstPointer<=mid){
        while (firstPointer<=mid){
        ans.push_back(nums[firstPointer]);
        firstPointer++;
        }
    }
    if(secondPointer<=end){
        while (secondPointer<=end){
        ans.push_back(nums[secondPointer]);
        secondPointer++;
        }
    }
    for(int i=0;i<ans.size();i++){
        nums[start+i] = ans[i];
    }
}

void mergeSort(vector<int>& nums,int start,int end){
    if(start<end){
        int mid = start + (end-start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
}

int main(){
    cout << "Enter the number of elements" << endl;
    int n;
    cin>>n;
    vector<int> nums;
    cout << "Enter the elements" << endl;
    for(int i=0;i<n;i++){
        int elem;
        cin>>elem;
        nums.push_back(elem);
    }
    mergeSort(nums,0,n-1);
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    return 0;
}