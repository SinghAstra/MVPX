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
    int start = 0;
    int mid = 0;
    int end = nums.size()-1;
    while(mid<=end){
        if(nums[mid]==0){
            swap(nums[start],nums[mid]);
            start++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else if(nums[mid]==2){
            swap(nums[mid],nums[end]);
            end--;
        }
    } 
    cout<<"Sorted "<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}