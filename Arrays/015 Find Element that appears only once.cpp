#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
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


// Hashing 
// Maps
// XOR

vector<int> hashing(vector<int> nums){
    int max = 0;
    for(int i = 0; i < nums.size();i++){
        if(nums[i] > max){
            max = nums[i];
        }
    }
    vector<int> hash(max+1, 0);
    for(int i = 0; i < nums.size();i++){
        hash[nums[i]]++;
    }
    return hash;
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
    vector<int> nums = {4,1,2,1,2};
    vector<int> ans = hashing(nums);
    printVector(ans);
}