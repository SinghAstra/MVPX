#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 

using namespace std;


int searchInSorted(int arr[], int N, int K) { 
    for(int i=0; i<N; i++){
        if(arr[i] == K){
            return 1;
        }
    }
    return 0;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int N = 9;
    int K = 8;
    cout << searchInSorted(arr,9,8);
}