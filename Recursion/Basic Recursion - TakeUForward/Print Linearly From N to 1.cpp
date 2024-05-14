#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


// Time Complexity : O(n)
// Space Complexity : O(n)
void printLinearly(int n){
    if(n == 0) return;
    cout << n << endl;
    printLinearly(n-1);
}

int main(){
    printLinearly(5);
    return 0;
}