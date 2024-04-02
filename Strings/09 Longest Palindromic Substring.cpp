#include "iostream"
#include "vector" 
#include <algorithm>    
#include <stack> 

using namespace std;
int main(){
    string s = "babad";
    int longestPalindromeLength = 0;
    string longestPalindrome = "";
   
    for(int center=0;center<s.size();center++){

        // Edge Case
        if(s.size()<=1){
        cout << "longestPalindrome"<<s<<endl;
        break;
        }

        // Case 1 : Palindrome with odd length
        int left = center;
        int right = center;
        while (left>=0&&right<s.size()&&s[left]==s[right])
        {
            left--;
            right++;
        }
        string palindromeString = s.substr(left+1, right-left-1);
        if(palindromeString.length()>longestPalindromeLength){
            longestPalindromeLength = palindromeString.length();
            longestPalindrome = palindromeString;
        }

        // Case 2 : Palindrome with even length
        left = center-1;
        right = center;
        while (left>=0&&right<s.size()&&s[left]==s[right])
        {
            left--;
            right++;
        }
        palindromeString = s.substr(left+1, right-left-1);
        if(palindromeString.length()>longestPalindromeLength){
            longestPalindromeLength = palindromeString.length();
            longestPalindrome = palindromeString;
        }
    }
    cout <<"longestPalindrome : "<<longestPalindrome<<endl;
    return 0;
}