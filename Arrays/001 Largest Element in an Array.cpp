#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

// Approach 1 : Brute Force Approach
// Sorting the array uses Quick Sort 
// Time Complexity : O(N logN)
// Space Complexity : O(logN) : Recursion depth
int largestElementBruteForce(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    return arr[n-1];        
}

// Approach 2 : Using Max Variable : Linear Search
// Time Complexity : O(n)
// Space Complexity : O(1)
int largestElementLinearSearch(vector<int> &arr, int n){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
int main(){
    vector<int> arr = {1, 2, 0, 3, 2, 4, 5};
    int n = arr.size();
    cout << "largest Element : "<<largestElementBruteForce(arr,n) << endl;
    cout << "largest Element : "<<largestElementLinearSearch(arr,n) << endl;
}