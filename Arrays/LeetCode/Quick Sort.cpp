#include "iostream"
#include "vector" 
#include <algorithm>      

using namespace std;


int partition(vector<int>& nums,int start,int end){
    int pivot = nums[start];
    int firstPointer = start;
    int secondPointer = end;
    while(firstPointer<secondPointer){
    while(nums[firstPointer]<=pivot){
        firstPointer++;
    }
    while(nums[secondPointer]>pivot){
        secondPointer--;
    }
    if(firstPointer<secondPointer){
        int temp = nums[firstPointer];
        nums[firstPointer] = nums[secondPointer];
        nums[secondPointer] = temp;
    }
    }
    int temp = nums[secondPointer];
    nums[secondPointer] = nums[start];
    nums[start] = temp;
    return secondPointer;
}

void quickSort(vector<int>& nums,int start,int end){
    if(start<end){
        int pivot = partition(nums,start,end);
        quickSort(nums,start,pivot-1);
        quickSort(nums,pivot+1,end);
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
    quickSort(nums,0,n-1);
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    return 0;
}