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
// Time Complexity : O(nlogn) 
// Space Complexity : O(n)
int majorityElementHashMap(vector<int> nums){
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


// Approach 3 : Moore's Voting Algorithm
// Time Complexity : O(2*n)
// Space Complexity : O(1)
int majorityElementMooreVotingAlgorithm(vector<int> nums){
    int count = 0;
    int majorityElement;
    int n = nums.size();
    for(int i = 0; i < n;i++){
        if(count==0){
            majorityElement = nums[i];
        }
        if(nums[i] == majorityElement){
            count++;
        }else{
            count--;
        }
    }
    int totalCount = 0;
    for(int i = 0; i < n;i++){
        if(nums[i] == majorityElement){
            totalCount++;
            if(totalCount > n/2){
                return majorityElement;
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