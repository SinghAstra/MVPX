#include "iostream"
#include "vector" 
#include <algorithm>    
#include <stack> 

using namespace std;
int main(){
    string s = "23[bc]";
    stack<int> num;
    stack<string> str;

     // Variable to store the current repetition count
    int currentRep = 0;

     // Iterate through the input string
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            // If the current character is a digit, build the repetition count
            if(isdigit(s[i+1])){
                currentRep = currentRep*10+(s[i]-'0');
                continue;
            }
            currentRep = currentRep*10 + (s[i]-'0');
            num.push(currentRep);
            cout << "currentRep: " << currentRep << endl;
            if(!isdigit(s[i+1])){
                // Reset currentRep after if next char is not a digit
                currentRep = 0;
            }
        }else if(s[i]==']'){
            string currentString;
            // Build the string until '[' is found
            while(str.top()!="["){
                currentString = str.top() + currentString; 
                str.pop();
            }
            str.pop(); // Pop '['
            // Get the repetition count
            int repTimes = num.top();
            num.pop();
            string ans;
             // Repeat the string and push it to the stack
            for(int j=0;j<repTimes;j++){
                ans+=currentString;
            }
            str.push(ans);
        }else{
              // If the current character is not a digit or ']', push it to the str stack
            str.push(string(1, s[i]));
        }
    }
    // Reconstruct the final string by popping from the str stack
    string ans = "";
    while(!str.empty()){
        ans = str.top() + ans;
        str.pop();
    }
    cout << "ans : " << ans << endl;
    return 0;
}