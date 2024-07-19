#include <bits/stdc++.h> 
using namespace std;

map<int,int> hashNumberArray(vector<int> nums){
    int len = nums.size();
    map<int,int> hashMap;
    for(int i=0;i<len;i++){
        hashMap[nums[i]]++;
    }
    return hashMap;
}


void printMap(map<int, int> hashMap){
    cout << "HashMap : " <<endl;
    for(auto it : hashMap){
        cout << it.first << "->" << it.second << endl;
    }
}

int main() {
    vector<int> nums = {1,2,3,4,5,9,5,5,3,2};
    map<int,int> result = hashNumberArray(nums);
    printMap(result);
}