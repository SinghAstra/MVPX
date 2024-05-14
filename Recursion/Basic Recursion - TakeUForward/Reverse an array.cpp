#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


void printArray(int* nums){
    int len = sizeof(nums);
    cout << "Elements in array are : ";
    for(int i = 0; i < len;i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void revArray(int* nums,int start,int end){
    if(start>=end){
        return ;
    }
    int temp = nums[start];
    nums[start] = nums[end];
    nums[end] = temp;
    printArray(nums);
    revArray(nums,start+1,end-1);
    // nums[0] = 6;
}

int main(){
    int nums[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(nums)/sizeof(nums[0]);
    printArray(nums);
    revArray(nums,0,len-1);
    printArray(nums);
    return 0;
}