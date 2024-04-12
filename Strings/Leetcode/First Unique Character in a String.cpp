#include "iostream"
#include "vector" 
#include <algorithm>    
#include <stack> 
#include <unordered_map> 

using namespace std;

int main(){
    // Approach 1 : Brute force
    string s  = "loveleetcode";
    for(int i = 0; i < s.size(); i++){
        bool found = false;
        for(int j = 0; j < s.size();j++){
            if(i == j ){
                continue;
            }
            if(s[j] == s[i]){
                found = true;
                break;
            }
        }
        if(found == false){
            cout << "First Unique Character : "<<i << endl;
            return i;
        }
    }
    cout << "First Unique Character : "<<-1<<endl;
    return -1;

    // Approach 2 : Optimized Approach
    string s  = "aabb";
    unordered_map<char, int> m;
    for(int i = 0; i < s.size(); i++){
        m[s[i]]++;
    }
    for(int i = 0; i < s.size(); i++){
        if(m[s[i]] == 1){
            cout << "First Unique Character : "<<i << endl;
            return i;
        }
    }
    cout << "First Unique Character : "<<-1<<endl;
    return -1;
}