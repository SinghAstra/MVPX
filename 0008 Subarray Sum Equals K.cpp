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
    int k;
    cout << "Enter the value of k ";
    cin>>k;

    // Time Complexity : O(n^2)
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

    int count = 0;
    int currentSum = nums[0];
    int start = 0;
    for(int i = 1; i<n;i++){
        cout << "i -> " << i << endl;
        cout<<"START"<<endl;
        cout << " currentSum -> " << currentSum << endl;
        cout << " start -> " << start << endl;
        cout<<" count -> " << count << endl;
        if(currentSum<k){
            currentSum += nums[i];
        }
        while (currentSum>k){
           currentSum -= nums[start];
           start++;
        }
        if(currentSum==k){
             while (currentSum==k){
                currentSum -= nums[start];
                start++;
                count ++;
            }
        }
        cout<<"END"<<endl;
        cout << " currentSum -> " << currentSum << endl;
        cout << " start -> " << start << endl;
        cout<<" count -> " << count << endl;
    }

    cout <<"count : "<<count<<endl;
    return 0;
}