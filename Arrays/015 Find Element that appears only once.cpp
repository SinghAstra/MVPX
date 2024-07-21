#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n^2)
// Space Complexity : O(1)
int elementThatAppearsOnlyOnceBruteForce(vector<int>& nums){
    int n = nums.size();
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(nums[i] == nums[j])
            {
                count++;
                if(count == 2){
                    break;
                }
            }
        }
        if(count == 1){
            return nums[i];
        }
    }
    return -1;
}


// Approach 2 : Using Array Hashing
// Time Complexity : O(n + 2*maxElem + 2 )
// Space Complexity : O(maxElem + 1)
int elementThatAppearsOnlyOnceArrayHashing(vector<int> nums){
    int n = nums.size();
    int maxElem = INT_MIN;
    for(int i = 0; i < n; i++){
        maxElem = max(maxElem, nums[i]);
    }
    vector<int> hash(maxElem+1, 0);
    for(int i = 0; i < n; i++){
        hash[nums[i]]++;
    }
    for(int i = 0; i < hash.size(); i++){
        if(hash[i] == 1){
            return i;
        }
    }
    return -1;
}

// Approach 3 : Using Unordered Map
// Time Complexity : O(2*n)
// Space Complexity : O(n)
int elementThatAppearsOnlyOnceMap(vector<int> nums){
    unordered_map<int,int> frequency;
    for(int i = 0; i < nums.size(); i++){
        frequency[nums[i]]++;
    }
    for(auto it = frequency.begin(); it!= frequency.end(); it++){
        if(it->second == 1){
            return it->first;
        }
    }
    return -1;
}

// Approach 4 : Using XOR
// Time Complexity : O(n)
// Space Complexity : O(1)
int elementThatAppearsOnlyOnceXOR(vector<int> nums){
    int result = 0;
    for(int i = 0; i < nums.size(); i++){
        result ^= nums[i];
    }
    return result;
}


int main(){
    vector<int> nums = {4,1,2,1,2};
    int ans = elementThatAppearsOnlyOnceXOR(nums);
    cout << "Element : "<<ans << endl;
    return 0;
}