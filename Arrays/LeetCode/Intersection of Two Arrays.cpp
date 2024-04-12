#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;

int main(){
    cout << "Enter the number of elements in array 1 " << endl;
    int n1;
    cin>>n1;
    vector<int> nums1;
    cout << "Enter the elements of array 1" << endl;
    for(int i=0;i<n1;i++){
        int elem;
        cin>>elem;
        nums1.push_back(elem);
    }
    cout << "Enter the number of elements in array 2 " << endl;
    int n2;
    cin>>n2;
    vector<int> nums2;
    cout << "Enter the elements of array 2" << endl;
    for(int i=0;i<n2;i++){
        int elem;
        cin>>elem;
        nums2.push_back(elem);
    }
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    set<int> s1;
    set<int> s2;
    vector<int> ans;
    for(int i=0;i<nums1.size();i++){
        s1.insert(nums1[i]);
    }
    for(int i=0;i<nums2.size();i++){
        s2.insert(nums2[i]);
    }
    for(auto itr:s1){
        if(s2.find(itr)!=s2.end()){
            ans.push_back(itr);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}