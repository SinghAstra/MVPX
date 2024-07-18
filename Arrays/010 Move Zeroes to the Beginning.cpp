#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;


// Approach 1 : Using External Array 
// Time Complexity : O(2*n)
// Space Complexity : O(n)
void moveZeroesToTheBeginningBruteForceApproach(vector<int>& nums){
    int n = nums.size();
    vector<int> temp;

    // Step 1: Collect all non-zero elements in a temporary vector
    for(int i = 0; i < n;i++){
        if(nums[i]!= 0){
            temp.push_back(nums[i]);
        }
    }
    int len = temp.size();
    int numberOfZeroes = n - len;

    // Step 2: Move the non-zero elements from the temporary vector back to the original array starting from the correct position
    for(int i = numberOfZeroes; i < n;i++){
        nums[i] = temp[i-numberOfZeroes];
    }

    // Step 3: Fill the beginning of the original array with zeroes
    for(int i = 0;i < numberOfZeroes;i++){
        nums[i] = 0;
    }
}


// Approach 2 : Using Two Pointers
// right pointer keeps track of where the non zero element should be placed
// left pointer scans the vector moving from right to left
// for non zero elements swap the elements and decrement both pointers
// for zero elements no swap happens and decrement only left pointer
// Time Complexity : O(n)
// Space Complexity : O(1)
void moveZeroesToTheBeginningTwoPointers(vector<int>& nums){
    int right = nums.size() - 1;
    for(int left = nums.size() - 1; left>=0; left--){
        if(nums[left] != 0){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            right--;
        }
    }

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
    vector<int> nums = {0, 1, 3, 0, 0, 6, 7, 8};
    moveZeroesToTheBeginningTwoPointers(nums);
    printVector(nums);
}