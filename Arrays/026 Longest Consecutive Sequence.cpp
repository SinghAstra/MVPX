#include<bits/stdc++.h>
using namespace std;

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

bool linearSearch(vector<int> nums,int elem){
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i] == elem)
            return true;
    }
    return false;
}

// Steps
// 1. Assume that each element is the start of a potential sequence
// 2. Check if consecutive elements exist in the array
// 3. Keep a count of the length of the current sequence
// 4. Update the longest streak

// Time Complexity : O(n^2)
// Space Complexity : O(1)
int longestConsecutiveBruteForce(vector<int>& nums) {
    int longestStreak = 0;
    int n = nums.size();
    for(int i=0;i<n;i++) {
        int element = nums[i] + 1;
        int count = 1;
        while(linearSearch(nums,element)){
            count++;
            element++;
        }
        longestStreak = max(longestStreak, count);
    }
    return longestStreak;
}

// Better Approach : Sorting Based Solution
// Time Complexity : O(nlogn + n)
// Space Complexity : O(1)
int longestConsecutiveBetterApproach(vector<int>& nums){
    int longestStreak = 0;
    int currentStreak = 1;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=1;i<n;i++){
        if(nums[i] == nums[i-1]){
            continue;
        }
        if(nums[i] == nums[i-1] + 1){
            currentStreak++;
            longestStreak = max(longestStreak, currentStreak);
        } else {
            currentStreak = 1;
        }
    }
    return longestStreak;
}


// Optimal Approach : Hash Set
// Time Complexity : O(n)
// Space Complexity : O(1)


// Observation : The key observation that transforms the brute force approach into the optimal 
// O(n) solution is recognizing that we only need to start counting the length of the consecutive 
// sequence from numbers that are the potential beginning of such a sequence. 
int longestConsecutiveOptimalApproach(vector<int>& nums){
    int n = nums.size();
    int longestStreak = 0;
    unordered_set<int> numSet;
    for(int i = 0; i < n;i++){
        numSet.insert(nums[i]);
    }    
    for(auto it = numSet.begin(); it != numSet.end(); it++){
        int num = *it;
        if(numSet.find(num-1) != numSet.end()){
            continue;
        }
        int currentStreak = 1;
        while(numSet.find(num+1)!= numSet.end()){
            num++;
            currentStreak++;
        }
        longestStreak = max(longestStreak, currentStreak);
    }
    return longestStreak;
}


int main(){
    vector<int> nums = {100,4,200,1,3,2};
    int n = nums.size();
    int ans = longestConsecutiveOptimalApproach(nums);
    cout << "Length of longest consecutive elements sequence : " << ans << endl;
    return 0;
} 



