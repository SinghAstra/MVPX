#include<bits/stdc++.h>
using namespace std;


// Approach 1 : Brute Force
// Time Complexity : O(n^2)
// Space Complexity : O(1)
int majorityElementBruteForce(vector<int> nums){
    int n = nums.size();
    for(int i = 0; i < n;i++){
        int elem = nums[i];
        int count = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] == elem){
                count++;
            }
        }
        if(count > n/2){
            return elem;
        }
    }
    return -1;
}

// Approach 2 : Using Hash Map
// Time Complexity : O(2*n)
// Space Complexity : O(1)
int majorityElementHashMapBetterApproach(vector<int> nums){
    unordered_map<int, int> countMap;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        countMap[nums[i]]++;
    }
    for(auto it = countMap.begin();it != countMap.end();it++){
        if(it->second > n/2){
            return it->first;
        }
    }
    return -1;
}

// Approach 3 : Using Hash Map
// Time Complexity : O(n) 
// Space Complexity : O(n)
int majorityElementHashMapBetterApproachThanBetterApproach(vector<int> nums){
    unordered_map<int, int> countMap;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        countMap[nums[i]]++;
        if(countMap[nums[i]] > n/2){
            return nums[i];
        }
    }
    return -1;
}


// Approach 4 : Moore's Voting Algorithm
// Moore's Voting Algorithm is used to find the majority element in list or array.
// The Algorithm has two phases: 
// 1. Candidate selection phase
// 2. Verification phase
// Time Complexity : O(2*n)
// Space Complexity : O(1)
int majorityElementMooreVotingAlgorithm(vector<int> nums){
    int count = 0;
    int candidateElem;
    int n = nums.size();
    // Phase 1 : Candidate selection phase
    for(int i = 0; i < n;i++){
        if(count==0){
            candidateElem = nums[i];
            count = 1;
        }
        if(nums[i] == candidateElem){
            count++;
        }else{
            count--;
        }
    }
    // Phase 2 : Verification phase
    int candidateCount = 0;
    for(int i = 0; i < n;i++){
        if(nums[i] == candidateElem){
            candidateCount++;
            if(candidateCount > n/2){
                return candidateElem;
            }
        }
    }
    return -1;
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
    vector<int> nums = {2,2,1,1,1,2,2};
    int n = nums.size();
    int majorityElement = majorityElementMooreVotingAlgorithm(nums);
    cout <<"Majority Element: " << majorityElement << endl;
    return 0;
}