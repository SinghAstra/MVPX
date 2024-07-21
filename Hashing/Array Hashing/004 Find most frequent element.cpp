#include <bits/stdc++.h>
using namespace std;

int mostFrequentElements(vector<int> nums){
    int n = nums.size();
    int maxElem = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] > maxElem){
            maxElem = nums[i];
        }
    }

    vector<int> frequency(maxElem+1,0);
    for(int i = 0; i < n; i++){
        frequency[nums[i]]++;
    }

    int maxIndex = 0;
    for(int i = 1; i < frequency.size(); i++){
        if(frequency[i] > frequency[maxIndex]){
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main(){
    vector<int> nums = {0,34,34,34,1,2,3};
    int num = mostFrequentElements(nums);
    cout << "Most frequent element: " << num << endl;
    return 0;
}