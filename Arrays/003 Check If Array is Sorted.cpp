#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

// Approach: Single Pass
// Time Complexity: O(n) 
// Space Complexity: O(1) 
bool isArraySorted(vector<int>& arr,int n){
    for(int i = 1; i < n; i++){
        if(arr[i-1] > arr[i]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> arr = {1, 2, 3, 3, 3, 1, 31};
    int n = arr.size();
    cout << " Array Sorted : "<<isArraySorted(arr,n) << endl;
}