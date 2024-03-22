#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;
int main(){
    string s = "hello world";
    // cout<< "Enter the String : "<<endl;
    // cin >> s;
    // Time Complexity : O(N)
    // Space Complexity : O(N)
    // vector<string> words;
    // string currentWord ="";
    // s = s +" ";
    // for(int i=0;i<s.size();i++){
    //     if(s[i]==' '){
    //         if(currentWord!=""){
    //         words.push_back(currentWord);
    //         }
    //         currentWord= "";
    //     }
    //     else{
    //         currentWord+=s[i];
    //     }
    // }
    // string ans = "";
    // for(int i=words.size()-1; i>=0;i--){
    //     ans += words[i];
    //     if(i!=0){
    //         ans += " ";
    //     }
    // }
    // cout<<"ans : "<<ans<<endl;

    // -------------------------------------------------------------------------------------------------------------

    // Time Complexity : O(N)
    // Space Complexity : O(1)
    string ans;
    string currentWord;
    s = s + " ";
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            if(currentWord!=""){
                 if(ans==""){
                    ans = currentWord;
                }else{
                ans=currentWord + " "+ ans;
                }
                currentWord="";
            }
        }
        else{
            currentWord+=s[i];
        }
    }
    cout << "ans : " << ans << endl;
    return 0;
}