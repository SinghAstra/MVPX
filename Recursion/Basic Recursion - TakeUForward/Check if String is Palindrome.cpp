#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


bool palindrome(string str,int low,int high){
    if(low>=high){
        return true;
    }
    if(str[low]!=str[high]){
        return false;
    }else{
        return palindrome(str,low+1,high-1);
    }
}

int main(){
    string str = "MADAM";
    bool isPalindrome = palindrome(str,0,str.size()-1);
    cout << "isPalindrome: " << isPalindrome << endl;
    return 0;
}