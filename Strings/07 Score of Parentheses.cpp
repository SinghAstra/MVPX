#include "iostream"
#include "vector" 
#include <algorithm>    
#include <stack> 

using namespace std;
int main(){
    string s = "(()(()))";

    // Stack to store the score of each opening parenthesis
    stack<int> score;
    int count = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            // If the current character is ')', calculate the score
            int currentValue = 0;
            // Sum up the scores of all characters until an opening parenthesis is found
            while(score.top()!=0){
                currentValue += score.top();
                score.pop();
            }
            score.pop(); // Pop the opening parenthesis score
            // Push the new score (twice the sum if it was a nested parentheses, else 1 for a single pair)
            if(currentValue ==0){
                score.push(1);
            }else{
                score.push(2*currentValue);
            }
        }else{
            // If the current character is '(', push 0 to indicate a new nesting level
            score.push(0);
        }
    }
    // Calculate the total score by summing up all scores in the stack
    int ans = 0;
    while(!score.empty()){
        ans += score.top();
        score.pop();
    }
    cout << "ans : "<< ans;
    return 0;
}