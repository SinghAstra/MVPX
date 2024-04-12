  #include "iostream"
#include "vector" 
#include <algorithm>    
#include <unordered_map> 

using namespace std;
int main(){
    // Given an integer, convert it to a Roman numeral string.
    int num = 1994;

    // Define the Roman numeral symbols and their corresponding values
    vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // Initialize an empty string to store the Roman numeral representation
    string ans = "";

    // Iterate through the values and symbols
    for (int i = 0; i < values.size(); i++) {
        // Repeat the current symbol while the number is greater than or equal to the current value
        while (num >= values[i]) {
            ans += symbols[i];
            num -= values[i];
        }
    }

    // Output the Roman numeral representation
    cout << "ans: " << ans << endl;
    return 0;
}