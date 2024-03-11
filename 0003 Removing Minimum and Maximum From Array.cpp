#include "iostream"
#include "vector" 
#include <algorithm>      

using namespace std;
int main(){
    cout << "Enter the number of elements" << endl;
    int n;
    cin>>n;
    vector<int> nums;
    cout << "Enter the elements" << endl;
    for(int i=0;i<n;i++){
        int elem;
        cin>>elem;
        nums.push_back(elem);
    }
    int minimum = INT_MAX;
    int minimum_index = 0;
    int maximum_index = 0;
    int maximum = INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i]<minimum){
            minimum = nums[i];
            minimum_index = i;
        }
        if(nums[i]>maximum){
            maximum = nums[i];
            maximum_index = i;
        }
    }
    int firstElemRem = max(maximum_index,minimum_index) + 1;
    int secondElemRem = max(n-1-maximum_index,n-1-minimum_index) + 1;
    int thirdElemRem = min(maximum_index,n-1-maximum_index)+min(minimum_index,n-1-minimum_index)+2;
    int elemRem = min(firstElemRem,min(secondElemRem,thirdElemRem));
    return 0;
}