#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
using namespace std;

vector<int> hashNumberArray(vector<int> nums){
    int max = 0;
    for(int i = 0; i < nums.size();i++){
        if(nums[i]>max){
            max = nums[i];
        }
    }

    vector<int> result(max+1,0);
    for(int i = 0; i < nums.size();i++){
        result[nums[i]]++;
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
    vector<int> nums = {1,2,3,4,5,9};
    vector<int> result = hashNumberArray(nums);
    printVector(result);
}