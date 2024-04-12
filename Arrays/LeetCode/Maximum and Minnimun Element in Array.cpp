#include "iostream"
#include "vector" 
#include <algorithm>      

using namespace std;
int main(){
     cout << "Enter the number of elements" << endl;
    int n;
    cin>>n;
    vector<int> arr;
    cout << "Enter the elements" << endl;
    for(int i=0;i<n;i++){
        int elem;
        cin>>elem;
        arr.push_back(elem);
    }
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    for(int i=0;i<n;i++){
        minimum = min(arr[i],minimum);
        maximum = max(arr[i],maximum);
    }
    cout << "Minimum element is " << minimum << endl;
    cout << "Maximum element is " << maximum << endl;
    return 0;
}