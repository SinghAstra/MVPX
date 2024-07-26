#include<bits/stdc++.h>
using namespace std;

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

    for(int i=0; i<pos.size(); i++){
        nums[2*i] = pos[i];
    }

    for(int i=0; i<neg.size();i++){
        nums[2*i+1] = neg[i];
    }
}


// Approach 2 : One Pass Approach
// Time Complexity : O(n)
// Space Complexity : O(n)
vector<int> reArrangeArrayElementBySignBetterApproach(vector<int> nums){
    int n = nums.size();
    vector<int> temp(n);
    int pos = 0, neg = 1;
    for(int i=0; i<n; i++){
        if(nums[i] >= 0){
            temp[pos] = nums[i];
            pos += 2;
        }else{
            temp[neg] = nums[i];
            neg += 2;
        }
    }
    return temp;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
// void reArrangeArrayElementBySign(vector<int>& nums){
//     int pos = 0;
//     int neg = 1;
//     int current = 0;
//     int n = nums.size();
//     while(current < n){
//         if(nums[current] >= 0){
//             if(current%2 == 0){
//                 current++;
//                 pos += 2;
//             }else{
//                 swap(nums[current], nums[pos]);
//             }
//         }else{
//             if(current%2 == 1){
//                 current++;
//                 neg += 2;
//             } else{
//                 swap(nums[current], nums[neg]);
//             }
//         }
//     }
// }


void printVector(vector<int> nums){
    int n = nums.size();
    cout << "Vector : ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {3,1,-2,-5,2,-4};
    int n = nums.size();
    reArrangeArrayElementBySignBetterApproach(nums);
    printVector(nums);
    return 0;
}