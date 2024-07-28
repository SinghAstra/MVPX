#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)
vector<vector<int>> rotateMatrixBruteForce(vector<vector<int>> matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> ans(cols, vector<int>(rows, 0));

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            ans[j][rows-1-i] = matrix[i][j];
        }
    }

    return ans;
}

// Steps:
// 1. Transpose the matrix
// 2. Reverse every row in the matrix
// Time Complexity : O(1.5*n*n) 
// Space Complexity : O(1)
void rotateMatrix(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i=0; i<rows; i++){
        for(int j=i; j<cols; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(int i=0; i<rows; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

}

void printMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
}



int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printMatrix(matrix);
    rotateMatrix(matrix);
    printMatrix(matrix);
    return 0;
} 



