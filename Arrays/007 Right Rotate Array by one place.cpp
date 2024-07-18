#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

// The reason for using a reverse direction iteration in the rightRotateArrayByOnePlace function
//  is to avoid overwriting elements prematurely. 
void rightRotateArrayByOnePlace(vector<int>& nums){
    int n = nums.size();
    int lastElement = nums[n-1];
    for(int i = n-1; i >= 0; i--){
        nums[i] = nums[i-1];
    }
    nums[0] = lastElement;
}

void printVector(vector<int> nums){
    int n = nums.size();
    cout << "Vector : ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    rightRotateArrayByOnePlace(nums);
    printVector(nums);
}