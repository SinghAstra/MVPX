#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Rules 
// 1. Negatives then positives 
// 2. Elements of opposite sign may or may not be equal.


// Observation 
// 1. Formula will be maintained for the 2*min elements

// Approach 1 : Brute Force
// Time Complexity : O(2*n)
// Space Complexity : O(1)
void rearrangeArrayElementsBySignBruteForce(vector<int>& nums){
    vector<int> pos;
    vector<int> neg;
    int n = nums.size();

    for(int i=0;i<n; i++){
        if(nums[i] >= 0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }

    int lPos = pos.size();
    int lNeg = neg.size();
    int min = (lPos < lNeg) ? lPos : lNeg;
    int np,pp;

    for(np = 0; np < min; np++){
        nums[2*np] = neg[np];
    }

    for(pp = 0; pp < min; pp++){
        nums[2*pp + 1] = pos[pp];
    }

    while(pp < lPos){
        nums[2*min + pp-min] = pos[pp];
        pp++;
    }

    while(np < lNeg){
        nums[2*min + np-min] = neg[np];
        np++;
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
    vector<int> nums = {1,2,3,-5};
    int n = nums.size();
    rearrangeArrayElementsBySignBruteForce(nums);
    printVector(nums);
    return 0;
} 



