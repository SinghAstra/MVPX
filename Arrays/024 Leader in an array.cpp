#include<bits/stdc++.h>
using namespace std;


// An element is said to be a leader if there is no element greater 
// than the particular element in the right side of the array


// Time Complexity : O(n^2)
// Space Complexity : O(n)
// Extra Space is required to return the leaders array
vector<int> findLeadersBruteForceApproach(vector<int> nums){
    int n = nums.size();
    vector<int> leaders;
    for(int i = 0; i < n;i++){
        bool isLeader = true;
        for(int j = i+1; j < n; j++){
            if(nums[j] > nums[i]){
                isLeader = false;
                break;
            }
        }
        if(isLeader){
            leaders.push_back(nums[i]);
        }
    }
    return leaders;
}


// Observation : Any element that is greater than or equal to the current maximum element from the right is a leader.
// Time Complexity : O(2*n)
// Space Complexity : O(n)
vector<int> findLeaders(vector<int> nums){
    int n = nums.size();
    vector<int> leaders;
    int max = INT_MIN;
    for(int i = n-1; i >= 0; i--){
        if(nums[i] >= max){
            max = nums[i];
            leaders.push_back(nums[i]);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
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
    vector<int> nums = {10,22,12,3,0,6};
    int n = nums.size();
    vector<int> leaders = findLeaders(nums);
    printVector(leaders);
    return 0;
} 



