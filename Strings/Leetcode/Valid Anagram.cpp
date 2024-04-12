#include "iostream"
#include "vector" 
#include <algorithm>    
#include <stack> 

using namespace std;
int main(){
    // Approach 1 : Brute Force Approach
    // Time Complexity : O(nlogn)
    string s = "rat";
    string t = "tar";
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t){
        cout << "Anagrams" << endl;
    }else{
        cout << "Not Anagrams" << endl;
    }
    // Approach 2 : Optimized Approach
    // Bucket Table
    // Time Complexity : O(n)
    // Space Complexity : O(1)
    vector<int> freqCount(26,0);
    if(s.size()!=t.size()){
        return false;
       }
    for(int i = 0; i <s.size(); i++){
        freqCount[s[i]-'a']++;
        freqCount[t[i]-'a']--;
    }
    for(int i = 0; i < freqCount.size(); i++){
        if(freqCount[i]!=0){
            cout << "Not Anagrams" << endl;
            return 0;
        }
    }
    cout << "Anagrams" << endl;

    return 0;
}
