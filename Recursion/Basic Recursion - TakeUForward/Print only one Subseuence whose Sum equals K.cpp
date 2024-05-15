#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <stack> 
using namespace std;


// Time Complexity : O(2^n)
// Space Complexity : O(log(n))
bool subSequence(int index, vector<int> sub){
    int arr[] = {1,2,1};
    int sum = 2;
    int len = sizeof(arr)/sizeof(arr[0]);
    if(index >= len){
        int currentSum = 0;
        for(int i = 0; i < sub.size(); i++){
            currentSum += sub[i];
        }
        if(currentSum == sum){
            cout << "SubSequence : ";
            for(int i = 0; i < sub.size(); i++){
                cout << sub[i] << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    sub.push_back(arr[index]);
    if(subSequence(index+1,sub)){
        return true;
    }else{
        sub.pop_back();
        return subSequence(index+1,sub);
    }
}

int main(){
    vector<int> sub = {};
    subSequence(0,sub);
    return 0;
}