#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


// Time Complexity : O(2^n)
// Space Complexity : O(log(n))
void subSequence(int index, vector<int> sub){
    int arr[] = {3,1,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    if(index >= len){
        cout << "SubSequence : ";
        for(int i = 0; i < sub.size(); i++){
            cout << sub[i] << " ";
        }
        cout << endl;
        return;
    }
    sub.push_back(arr[index]);
    subSequence(index+1,sub);
    sub.pop_back();
    subSequence(index+1,sub);
}

int main(){
    vector<int> sub = {};
    subSequence(0,sub);
    return 0;
}