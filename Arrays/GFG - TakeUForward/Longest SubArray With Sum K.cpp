#include "iostream"
#include "vector" 
#include <algorithm>    
#include <set> 
#include <unordered_map> 

using namespace std;

// Approach 1 : Brute Force
// Time Complexity : O(n^3)
// Space Complexity : O(1)
int longSubArrayBruteForce(int A[],  int N, int K) { 
    int len = N;
    int maxLen = 0;
    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            int start = i;
            int end = j;
            int sum = 0;
            while(start <= end){
                sum += A[start];
                if(sum == K){
                    maxLen = max(maxLen, start - i + 1);
                }
                start++;
            }
        }
    }
    return maxLen;
} 



// Approach 2 : Better Brute Force
// Time Complexity : O(n^2)
// Space Complexity : O(1)
int longSubArrayBetterBruteForce(int A[],  int N, int K) { 
    int len = N;
    int maxLen = 0;
    for(int i = 0; i < len; i++){
        int sum = 0;
        for(int j = i; j < len; j++){
            sum += A[j];
            if(sum == K){
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
} 


// Approach 3 : Prefix Sum with Hash Map Approach
// Time Complexity :O(N)
// Space Complexity :O(N)
int longSubArrayHashMap(int A[], int N, int K){
    int  len = N;
    int maxLen = 0;
    int sum = 0;
    unordered_map<int, int> prefixSum;
    for(int i = 0; i <len; i++){
        sum += A[i];
        if(sum == K){
            maxLen = max(maxLen, i + 1);
        }
        if(prefixSum.find(sum - K)!= prefixSum.end()){
            maxLen = max(maxLen, i - prefixSum[sum - K]);
        }
        if(prefixSum.find(sum) == prefixSum.end()){
            prefixSum[sum] = i;
        }
    }
    return maxLen;
}


// Approach 4 : Using Two Pointers
// Time Complexity : O(2*N)
// Space Complexity : O(1)
int longSubArrayTwoPointers(int A[],int N,int K){
    int start = 0;
    int end = 0;
    int currentSum = 0;
    int maxLen = 0;
    while(end < N){
        currentSum += A[end];
        while(currentSum > K){
            currentSum -= A[start];
            start++;
        }
        if(currentSum == K){
            maxLen = max(maxLen, end - start + 1);
        }
        end++;
    }
    return maxLen;
}


int main(){
    int A[] = {10,5,2,7,1,9};
    int N = sizeof(A)/sizeof(A[0]);
    int K = 15;
    int maxLen = longSubArrayTwoPointers(A,N ,K);
    cout << "maxLen: " << maxLen << endl;
    return 0;
}