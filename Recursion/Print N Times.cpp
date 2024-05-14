#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;

void printNTimes(int n){
    if(n == 0) return;
    cout << "Programming" << endl;
    printNTimes(n-1);
}

int main(){
    printNTimes(5);
    return 0;
}