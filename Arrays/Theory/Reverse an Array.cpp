#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


// Approach 1 : Brute Force
// Time Complexity : O(n)
// Space Complexity : O(n)
int* reverseArrayBruteForce(int* array){
    int len = sizeof(array);
    int* revArray = new int[len];
    for(int i = 0; i < len; i++){
        revArray[len - i - 1] = array[i];
    }
    return revArray;
}


// Approach 2 : Optimal Approach - Two Pointer Approach
// Time Complexity : O(n/2)
// Space Complexity : O(1)
void reverseArrayTwoPointer(int* array){
    int len = sizeof(array);
    int start = 0;
    int end = len - 1;
    while(start < end){
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

void printArray(int* nums){
    int len = sizeof(nums);
    cout << "Elements in array are : ";
    for(int i = 0; i < len;i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    int nums[] = {1,2,3,4,5,6,7,8};
    printArray(nums);
    reverseArrayTwoPointer(nums);
    printArray(nums);
    return 0;
}