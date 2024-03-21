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
    for(int i=0;i<n-1;i++){
        int min = nums[i];
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<min){
                min = nums[j];
                minIndex = j;
            }
        }
        if(minIndex!=i){
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
    }
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    return 0;
}