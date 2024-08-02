#include<bits/stdc++.h>
using namespace std;

// (A) Find the element at the nth row and nth column
// An element at the nth row and nth column is (n-1)C(r-1)
// Time Complexity : O(r)
// Space Complexity : O(1)
int elementAtTheNthRowAndNthColumn(int row, int column){
    int ans = 1;
    for(int i=1; i<column; i++){
        ans *= (row - i);
        ans /= i;
    }
    return ans;
}

// (B) Find all elements in the nth row
// Time Complexity : O(n*r)
vector<int> elementsInNthRowBruteForce(int n){
    vector<int> ans;
    for(int i=1; i<=n; i++){
        ans.push_back(elementAtTheNthRowAndNthColumn(n, i));
    }
    return ans;
}

// Time Complexity : O(n)
vector<int> elementsInNthRowBetterApproach(int n){
    vector<int> ans(n);
    ans[0] = 1;
    for(int i=1; i<n; i++){
        ans[i] = ans[i-1]*(n-i)/i;
    }
    return ans;
}


// (C) Find the first n rows of the pascals triangle
// Time Complexity : O(n*n*r)
vector<vector<int>> elementInNRowsBruteForce(int n){
    vector<vector<int>> pascalsTriangle;
    for(int i=0; i<n; i++){
        vector<int> row = elementsInNthRowBruteForce(i+1);
        pascalsTriangle.push_back(row);
    }
    return pascalsTriangle;
}

// Time Complexity : O(n*n)
vector<vector<int>> elementInNRowsBetterApproach(int n){
    vector<vector<int>> pascalsTriangle(n);
    for(int i=0; i<n; i++){
        vector<int> row = elementsInNthRowBetterApproach(i+1);
        pascalsTriangle[i] = row;
    }
    return pascalsTriangle;
}

void printVector(vector<int> nums){
    int n = nums.size();
    cout << "Vector : ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
}


int main(){
    vector<vector<int>> nums = elementInNRowsBetterApproach(5);
    printMatrix(nums);
    return 0;
}