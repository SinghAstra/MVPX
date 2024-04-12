#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;
int main(){
    vector<string> strs ={"flower","flow","flight"};
     string ans = "";

    
    // Approach 1 : Brute Force
    // TIme Complexity : O(N^2)
    // Space Complexity : O(1)
    // Given a list of strings, find the longest common prefix among them.
    vector<string> strs = {"flower", "flow", "flight"};
    string ans = "";

    // Iterate over each character position in the first string
    for (int i = 0; i < strs[0].length(); i++) {
        // Take the current character from the first string
        char currentChar = strs[0][i];
        bool common = true;
        
        // Compare the current character with the corresponding character in other strings
        for (int j = 1; j < strs.size(); j++) {
            string currentString = strs[j];
            // If the characters don't match, set common to false and exit the loop
            if (currentString[i] != currentChar) {
                common = false;
                break;
            }
        }
        
        // If all characters were common at this position, add the character to the prefix
        if (common) {
            ans += currentChar;
        } else {
            // If there was a mismatch, break out of the loop
            break;
        }
    }
    // The variable 'ans' now contains the longest common prefix among the strings
    cout <<"ans : " << ans << endl;

    // Approach 2 : Efficient Method
    // Time Complexity : O(N)
    // Space Complexity : O(1)
    // Sort the strings alphabetically
    
    // Sort the strings lexicographically
    sort(strs.begin(), strs.end());

    // Iterate over each character position in the first string
    for (int i = 0; i < strs[0].length(); i++) {
        // Check if the character at this position is the same in the first and last strings
        if (strs[0][i] == strs[strs.size() - 1][i]) {
            // If it is the same, add the character to the result
            ans += strs[0][i];
        } else {
            // If there is a mismatch, break out of the loop
            break;
        }
    }
    // The variable 'ans' now contains the longest common prefix among the sorted strings
    cout <<"ans : " << ans << endl;
    return 0;
}