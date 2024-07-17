#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

// Approach 1 : Using Set
// Time Complexity : O((n+m)(2+log(n+m)))
// Space Complexity : O(3(n+m))
vector<int> unionOfTwoSortedArrayBruteForce(vector<int> nums1, vector<int> nums2){
    int len1 = nums1.size();
    int len2 = nums2.size();
    vector<int> nums;
    set<int> unique;
    
    // Step 1: Combine both the arrays
    for(int i = 0; i < len1;i++){
        nums.push_back(nums1[i]);
    }
    for(int i = 0; i < len2;i++){
        nums.push_back(nums2[i]);
    }

    // Step 2 : Remove duplicates by using set
    // Integrating element into set takes O(log(k)) time where k is the current size of the set
    for(int i = 0; i < nums.size(); i++){
        unique.insert(nums[i]);
    }

    // Step 3: Convert set to vector
    vector<int> result;
    for(auto it = unique.begin(); it!= unique.end(); it++){
        result.push_back(*it);
    }
    return result;
}


// Approach 2 : Using Two Pointers
// Time Complexity : O(n + m + min(n,m))
// Space Complexity : O(n + m)
vector<int> unionOfTwoSortedArrayTwoPointerApproach(vector<int>& nums1, vector<int>& nums2){
    // Step 1: Initialize result vector and pointers for both arrays
    vector<int> result;
    int i = 0, j = 0;
    int len1 = nums1.size();
    int len2 = nums2.size();

    // Step 2: Traverse both arrays using the two pointers
    while(i < len1 && j < len2){
        if(nums1[i] < nums2[j]){

            // Step 3: Add unique elements from nums1 to result
            if(result.empty()||result.back()!=nums1[i]){
                result.push_back(nums1[i]);
            }
            i++;
        }else if(nums2[j] < nums1[i]){

            // Step 4: Add unique elements from nums2 to result
            if(result.empty()||result.back()!=nums2[j]){
                result.push_back(nums2[j]);
            }
            j++;
        }else{

            // Step 5: Both elements are equal, add one of them to result
            if(result.empty()||result.back()!=nums2[j]){
                result.push_back(nums2[j]);
            }
            i++;
            j++;
        }
    }

    // Step 6: Add remaining elements from nums1, if any
    while (i<len1)
    {
        if(result.empty()||result.back()!=nums1[i]){
            result.push_back(nums1[i]);
        }
        i++;
    }

    // Step 7: Add remaining elements from nums2, if any
    while(j<len2){
        if(result.empty()||result.back()!=nums2[j]){
            result.push_back(nums2[j]);
        }
        j++;
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
    vector<int> nums = unionOfTwoSortedArrayTwoPointerApproach(nums1, nums2);
    printVector(nums);
}