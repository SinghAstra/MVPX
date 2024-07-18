#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

vector<int> hashStringOfLowerCaseCharactersOnly(string str){
    vector<int> result(26,0);
    for(int i=0; i<str.size(); i++){
        result[str[i]-'a']++;
    }
    return result;
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
    string str = "abcdfrzzzzz";
    vector<int> result = hashStringOfLowerCaseCharactersOnly(str);
    printVector(result);
}