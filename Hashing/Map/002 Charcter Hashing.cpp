#include <bits/stdc++.h> 
using namespace std;

map<char,int> hashCharacterArray(vector<char> nums){
    int len = nums.size();
    map<char,int> hashMap;
    for(int i=0;i<len;i++){
        hashMap[nums[i]]++;
    }
    return hashMap;
}


void printMap(map<char, int> hashMap){
    cout << "HashMap : " <<endl;
    for(auto it : hashMap){
        cout << it.first << "->" << it.second << endl;
    }
}

int main() {
    vector<char> nums = {'a','b','c','d','e','f','b','a','A',};
    map<char,int> result = hashCharacterArray(nums);
    printMap(result);
}