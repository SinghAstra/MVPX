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

// Time Complexity : O(N)
// Space Complexity : O(1)
void rotateArrayByOnePlace(vector<int> &nums){
    int firstElem = nums[0];
    int n = nums.size();
    for(int i = 1; i < n; i++){
        nums[i-1] = nums[i];
    }
    nums[n - 1] = firstElem;
}


int main(){
    vector<int> nums = {0,1,2,3,4,5,6,7};
    rotateArrayByOnePlace(nums);
    printVector(nums);
    return 0;
}