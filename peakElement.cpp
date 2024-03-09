#include <iostream>

using namespace std;

int findPivot(int* arr,int l,int h,int n){
    int mid = l + (h-l)/2;
    if((mid==0||arr[mid]>=arr[mid-1])&&mid==n-1||arr[mid]>=arr[mid+1]){
        return mid;
    }
    if(mid!=0&&arr[mid]<arr[mid-1]){
        return findPivot(arr,l,mid-1,n);
    }else{
        return findPivot(arr,mid+1,h,n);
    }
}

int main(){
    cout << "Enter the number of elements in the array" << endl;
    int n;
    cin>>n;
    int* arr = new int[n];
    cout << "Enter the elements of the array" << endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pivotIndex = findPivot(arr,0,n-1,n);
    cout << "The pivot index is " << pivotIndex << endl;
    return 0;
}

