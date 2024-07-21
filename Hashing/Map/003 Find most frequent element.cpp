#include <bits/stdc++.h> 
using namespace std;


int mostFrequentElement(vector<int> nums){
    unordered_map<int, int> freq;
    for(int i=0; i<nums.size();i++){
        freq[nums[i]]++;
    }

    int maxFreq = -1;
    int maxFreqElement = -1;
    for(auto it=freq.begin();it!=freq.end();it++){
        if(it->second > maxFreq){
            maxFreq = it->second;
            maxFreqElement = it->first;
        }
    }

    return maxFreqElement;
}

int main(){
    vector<int> nums = {0,1,2,3,4,5,6,7,989,989,989};
    int num = mostFrequentElement(nums);
    cout << "Most frequent element: " << num << endl;
    return 0;
}