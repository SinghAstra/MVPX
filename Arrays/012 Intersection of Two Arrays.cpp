#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

// Approach 1 : Brute Force Approach 
// Time Complexity : O(n*(m+min(m,n)))
// Space Complexity : O(min(m,n))
vector<int> intersectionOfTwoSortedArraysBruteForceApproach(vector<int> nums1, vector<int> nums2){
     // Initialize an empty vector to store the intersection elements
    vector<int> result;

    // Get the size of the first and second arrays
    int len1 = nums1.size();
    int len2 = nums2.size();

    // Loop through each element in the first array
    for(int i = 0; i < len1; i++) {
        // Initialize a flag to check if the element is found in the second array
        bool isFound = false;

        // Loop through each element in the second array to check for presence of nums1[i]
        for(int j = 0; j < len2; j++) {
            if(nums1[i] == nums2[j]) {
                // If the element is found in the second array, set the flag to true and break the loop
                isFound = true;
                break;
            }
        }

        // Initialize a flag to check if the element is already in the result vector
        bool isInResult = false;

        // Loop through the result vector to ensure there are no duplicates
        for(int j = 0; j < result.size(); j++) {
            if(nums1[i] == result[j]) {
                // If the element is already in the result vector, set the flag to true and break the loop
                isInResult = true;
                break;
            }
        }

        // If the element is found in the second array and not already in the result vector, add it to the result vector
        if(isFound && !isInResult) {
            result.push_back(nums1[i]);
        }
    }
    return result;
}


// Approach 2 : Using Two Pointers
// Time Complexity : O(n log(n)) + O(m log(m)) + O(min(n,m))
// Space Complexity : O(min(n,m))
vector<int> intersectionOfTwoSortedArraysTwoPointerApproach(vector<int>& nums1, vector<int>& nums2){
    int i = 0, j = 0;
    vector<int> result;
    int len1 = nums1.size();
    int len2 = nums2.size();

    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

    while(i<len1 && j<len2){
        if(nums1[i] < nums2[j]){
            i++;
        }else if(nums1[i] >nums2[j]){
            j++;
        }else{
            if(result.empty() || result.back()!= nums1[i]){
                result.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }
    return result;
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
    vector<int> nums1 = {0, 1, 1, 2, 3};
    vector<int> nums2 = {0, 1, 1, 2, 3, 4};
    vector<int> nums = intersectionOfTwoSortedArraysBruteForceApproach(nums1, nums2);
    printVector(nums);
}