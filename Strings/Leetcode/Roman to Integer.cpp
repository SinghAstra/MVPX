#include "iostream"
#include "vector" 
#include <algorithm>    
#include <unordered_map> 

using namespace std;
int main(){
    // Given a Roman numeral string, convert it to an integer.
    string s = "MCMXCIV";

    // Map Roman numerals to their integer values
    unordered_map<char, int> values;
    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;

    // Initialize result and a variable to keep track of the previous value
    int result = 0;
    int prevValue = INT_MIN;

    // Iterate through the string from right to left
    for (int i = s.size() - 1; i >= 0; i--) {
        // If the current value is less than the previous value, subtract it
        if (values[s[i]] < prevValue) {
            result -= values[s[i]];
        } else {
            // Otherwise, add it to the result
            result += values[s[i]];
        }
        // Update the previous value
        prevValue = values[s[i]];
    }

    // Output the result
    cout << "result: " << result;
    return 0;
}