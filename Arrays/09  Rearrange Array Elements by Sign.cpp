#include "iostream"
#include "vector" 
#include <algorithm>    
#include <unordered_map> 

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

    // Time Complexity : O(N/2) + O(N)
    // Space Complexity : O(N)
    vector<int> posNums;
    vector<int> negNums;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(nums[i]>=0){
            posNums.push_back(nums[i]);
        }
        else{
            negNums.push_back(nums[i]);
        }
    }
    for(int i=0; i<n/2;i++){
        ans[2*i] = posNums[i];
        ans[2*i+1] = negNums[i];
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }

    // Time Complexity : O(N)
    // Space Complexity : O(N)
    int posPointer = 0;
    int negPointer = 1;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(nums[i]>=0){
            ans[posPointer] = nums[i];
            posPointer += 2;
        }
        else{
            ans[negPointer] = nums[i];
            negPointer += 2;
        }
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}