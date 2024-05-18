#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;

// Time Complexity : O(n log(n))
// Space Complexity : O(log(n))
int print2largestBruteForce(int arr[], int n) {
    sort(arr,arr+n);
    return arr[n-2];
}


// Time Complexity : O(2*n)
// Space Complexity : O(1)
int print2largestBetter(int arr[], int n) {
    int largest = -1;
    int secondLargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>secondLargest&&arr[i]!=largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
int print2LargestOptimal(int arr[],int n){
    int largest = arr[0];
    int secondLargest = -1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }else if(arr[i]>secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main(){
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "secondLargest : "<<print2largestBetter(arr,n)<<endl;
    cout << "secondLargest : "<<print2LargestOptimal(arr,n)<<endl;
    return 0;
}