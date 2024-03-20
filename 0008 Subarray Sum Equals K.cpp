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
    int k;
    cout << "Enter the value of k ";
    cin>>k;

    // Time Complexity : O(n^2)
    // Approach : Form all the subArray and calculate the sum for each subArray
    // int count = 0;
    // for(int i = 0; i < nums.size();i++){
    //     int currentSum = 0;
    //     for(int j = i; j <nums.size();j++){
    //         currentSum += nums[j];
    //         if(currentSum == k){
    //             count++;
    //         }
    //     }
    // }


    // Time Complexity : O(N)
    // Approach : Sliding window Algorithm
    // Limitation : Only Non-Negative Number
    // int count = 0;
    // int currentSum = nums[0];
    // int start = 0;
    // for(int i = 1; i<n;i++){
    //     if(currentSum<k){
    //         currentSum += nums[i];
    //     }
    //     while (currentSum>k){
    //        currentSum -= nums[start];
    //        start++;
    //     }
    //     if(currentSum==k){
    //          while (currentSum==k){
    //             currentSum -= nums[start];
    //             start++;
    //             count ++;
    //         }
    //     }
    // }
    // cout <<"count : "<<count<<endl;


    // Time Complexity : O(N)
    // Approach : Prefix Sum
    int prefixSum = 0;
    int count = 0;
    unordered_map<int,int> sum; 
    sum[prefixSum] = 1;
    for(int i=0;i<n;i++){
        prefixSum += nums[i];
        int remSum = prefixSum - k;
        if(sum.find(remSum) != sum.end()){
            count += sum[remSum];
        }
        sum[prefixSum]++;
    }
    cout << "count : "<<count<<endl;
    return 0;
}