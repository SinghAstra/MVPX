#include "iostream"
#include "vector" 
#include <algorithm>    
#include <stack> 
#include <unordered_map> 

using namespace std;

string getFrequencyCount(string s){
        vector<int> freqCount(26,0);
        for(auto& c:s){
            freqCount[c - 'a']++;
        }
        string frequencyCount;
        for(auto& count:freqCount){
            frequencyCount += string(1,count)+"#";
        }
        return frequencyCount;
    }

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    // Method 1 : Categorize by Sorting
    // Anagrams Property : If Sorted All Anagrams are same
    // Time Complexity : O(n*n*log n)
    unordered_map<string,vector<string>> stringAnagramsMap;
    vector<vector<string>> groupedAnagrams;

    for(int i=0; i<strs.size();i++){
        string key = strs[i];
        sort(key.begin(), key.end());
        stringAnagramsMap[key].push_back(strs[i]);
    }

    for(auto& s : stringAnagramsMap){
        groupedAnagrams.push_back(s.second);
    }

    for(int i=0; i<groupedAnagrams.size();i++){
        for (int j=0;j<groupedAnagrams[i].size();j++){
            cout << groupedAnagrams[i][j] << " ";
        }
        cout << endl;
    }

    // Method 2 : Categorize by Frequency
    // Time Complexity : O(n*n)
    unordered_map<string,vector<string>> stringAnagramsMap;
    vector<vector<string>> groupedAnagrams;

    for(int i=0; i<strs.size();i++){
        string key = getFrequencyCount(strs[i]);
        stringAnagramsMap[key].push_back(strs[i]);
    }

    for(auto& s : stringAnagramsMap){
        groupedAnagrams.push_back(s.second);
    }

    for(int i=0; i<groupedAnagrams.size();i++){
        for (int j=0;j<groupedAnagrams[i].size();j++){
            cout << groupedAnagrams[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}