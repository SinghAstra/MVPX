#include "iostream"
#include "vector" 
#include <algorithm>    
#include <stack> 

using namespace std;
int main(){
    string s = "egg";
    string t = "add";

     // Vectors to store the mapping of characters from s to t
    vector<char> chars1;
    vector<char> chars2;

    // Check if the lengths of s and t are equal
    if(s.length()==t.length()){
        for(int i=0;i<s.length();i++){

                // Check if the character from s already has a mapping to a different character in t
            if(find(chars1.begin(),chars1.end(),s[i])!=chars1.end()){
                if(chars2[find(chars1.begin(),chars1.end(),s[i])-chars1.begin()]!=t[i]){
                    cout << false;// Characters in s map to different characters in t, not isomorphic
                }
            }else if(find(chars2.begin(),chars2.end(),t[i])!=chars2.end()){
                cout << false;// Character in t is already mapped to a different character in s, not isomorphic
            }else{
                chars1.push_back(s[i]);
                chars2.push_back(t[i]);
            }
        }
    }else{
        cout << false;// Lengths of s and t are different, not isomorphic
    }
    cout << true; // Strings are isomorphic
    return 0;
}