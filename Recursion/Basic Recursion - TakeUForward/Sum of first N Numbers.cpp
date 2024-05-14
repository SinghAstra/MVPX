#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


int sum(int n){
    if(n==1){
        return 1;
    }
    return n+sum(n-1);
}

int main(){
    int ans = sum(6);
    cout << "Sum is "<<ans<<endl;
    return 0;
}