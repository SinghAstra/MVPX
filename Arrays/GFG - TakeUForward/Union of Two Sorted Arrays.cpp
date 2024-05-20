#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;


void printVector(vector<int> nums){
    int len = nums.size();
    cout << "[";
    for(int i = 0; i < len;i++){
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}

// Approach : Two Pointer Approach
// Time Complexity : O(n)
// Space Complexity : O(n)
vector<int> findUnion(int arr1[], int arr2[], int n, int m){
    int first = 0;
    int second = 0;
    vector<int> ans;
    while(first < n && second < m){
        if(arr1[first] < arr2[second]){
            if(ans.size()==0||ans.back()!=arr1[first]){
            ans.push_back(arr1[first]);
            }
            first++;
        }
        else{
            if(ans.size()==0||ans.back()!=arr2[second]){
            ans.push_back(arr2[second]);
            }
            second++;
        }
    }
    while(first < n){
        if(ans.size()==0||ans.back()!=arr1[first]){
        ans.push_back(arr1[first]);
        }
        first++;
    }
    while(second < m){
        if(ans.size()==0||ans.back()!=arr2[second]){
            ans.push_back(arr2[second]);
        }
        second++;
    }
    return ans;
}

int main(){
    int arr1[] = {1,2,3,4,5};
    int n = 5;
    int arr2[] = {3,4,5,6,7};
    int m = 5;
    vector<int> result = findUnion(arr1, arr2, n, m);
    printVector(result);
    return 0;
}