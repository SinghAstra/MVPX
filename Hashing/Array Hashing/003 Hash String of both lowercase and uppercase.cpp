#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;


vector<int> hashStringOfLowercaseAndUppercase(string str){
    vector<int> hash(256,0);
    for(int i=0; i<str.length(); i++){
        hash[str[i]]++;
    }
    return hash;
}


void printVector(vector<int> nums){
    int n = nums.size();
    cout << "Vector : ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    string str = "aaaaaaaabcdfrzzzzAAANBNNBZZ$%z";
    vector<int> result = hashStringOfLowercaseAndUppercase(str);
    printVector(result);
}