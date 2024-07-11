#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

// Approach 1 : Brute Force Approach
// Sorting the array uses Quick Sort 
// Time Complexity : O(N logN + N)
// Space Complexity : O(logN) : Recursion depth
int secondLargestElementBruteForce(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    int largestElement = arr[n-1];
    int secondLargestElement = INT_MIN;
    for(int i=n-2; i>=0; i--){
        if(arr[i] < largestElement){
            secondLargestElement = arr[i];
            break;
        }
    }
    return secondLargestElement;        
}

// Approach 2 : Two Pass Scan
// Time Complexity : O(2*N)
// Space Complexity : O(1)
int secondLargestElementTwoPassScan(vector<int>& arr, int n){
    int largestElement = INT_MIN;
    int secondLargestElement = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>largestElement){
            largestElement = arr[i];
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i]!= largestElement && arr[i]>secondLargestElement){
            secondLargestElement = arr[i];
        }
    }
    return secondLargestElement;
}

// Approach 3: Single Pass
// Time Complexity : O(N)
// Space Complexity : O(1)
int secondLargestElementSinglePass(vector<int>& arr,int n){
    int largestElement = arr[0];
    int secondLargestElement = INT_MIN;
    for(int i=1;i<=n;i++){
        if(arr[i] > largestElement){
            secondLargestElement = largestElement;
            largestElement = arr[i];
        }
        else if(arr[i] > secondLargestElement && arr[i]!= largestElement){
            secondLargestElement = arr[i];
        }
    }
    return secondLargestElement;
}

int main(){
    vector<int> arr = {1, 2, 3, 3, 3, 1, 1};
    int n = arr.size();
    cout << " Second largest Element : "<<secondLargestElementBruteForce(arr,n) << endl;
    cout << " Second largest Element : "<<secondLargestElementTwoPassScan(arr,n) << endl;
    cout << " Second largest Element : "<<secondLargestElementSinglePass(arr,n) << endl;
}