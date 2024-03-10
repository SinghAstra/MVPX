#include <iostream>
#include <vector>
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
    int l = 0;
    int r = n-1;
    int mid = l+(r-l)/2;
    while(l<=r){
        mid = l+(r-l)/2;
        cout<<"l = "<<l<<endl;
        cout<<"r = "<<r<<endl;
        cout<<"mid = "<<mid<<endl;
        if((mid==0||arr[mid]>=arr[mid-1])&&(mid==n-1||arr[mid]>=arr[mid+1])){
            cout<<"peak ->"<< mid <<endl;
            break;
        }
        if(mid!=0&&arr[mid]<=arr[mid-1]){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout<<"mid ->"<<mid<<endl;
    return 0;
}