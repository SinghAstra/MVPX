#include<bits/stdc++.h>
using namespace std;


void markRow(vector<vector<int>>& matrix, int row) {
    int cols = matrix[0].size();
    for(int j=0; j<cols; j++){
        if(matrix[row][j] != 0){
            matrix[row][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& matrix, int col) {
    int rows = matrix.size();
    for(int i=0; i<rows; i++){
        if(matrix[i][col] != 0){
            matrix[i][col] = -1;
        }
    }
}

// Time Complexity : O(m*n*(m+n))
// Space Complexity : O(1)
// Steps :
// 1. Identify all zero positions
// 2. Mark Row And Column elements by changing them to -1
// 3. Set the matrix element to zero
void setMatrixZeroBruteForce(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == 0){
                markRow(matrix, i);
                markCol(matrix, j);
            }
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
}

// Time Complexity : O(3*m*n)
// Space Complexity : O(m+n)
// Steps :
// 1. Identity zero position
// 2. Mark the rowIndex and columnIndex
// 3. Set the elements in the matrix at rowIndex and columnIndex as zero
// Observation :
// Instead of marking all the elements as -1 just mark the rowIndex and columnIndex.
void setMatrixZeroesBetterApproach(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> rowMark(rows,1);
    vector<int> colMark(cols,1);

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == 0){
                rowMark[i] = 0;
                colMark[j] = 0;
            }
        }
    }

    for(int i=0; i<rows; i++){
        if(rowMark[i] == 0){
            for(int j=0; j<cols; j++){
                matrix[i][j] = 0;
            }
        }
    }

    for(int j=0; j<cols; j++){
        if(colMark[j] == 0){
            for(int i=0; i<rows; i++){
                matrix[i][j] = 0;
            }
        }
    }

}


// Observation : In order to prevent using extra space use the first row and first column 
// of the matrix as marker.
// Time Complexity : O(n^2)
// Space Complexity : O(1)
void setMatrixZeroes(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int rowMark = 1;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] == 0){
                if(i!=0){
                matrix[i][0] = 0;
                }else{
                    rowMark = 0;
                }
                matrix[0][j] = 0;
            }
        }
    }

    for(int i=1; i<rows; i++){
        if(matrix[i][0] == 0){
        for(int j=0; j<cols; j++){
            matrix[i][j] = 0;
        }
        }
    }

    for(int j=0; j<cols; j++){
        if(matrix[0][j] == 0){
        for(int i=0; i<rows; i++){
            matrix[i][j] = 0;
        }
        }
    }

    if(rowMark == 0){
        for(int j=0; j<cols; j++){
            matrix[0][j] = 0;
        }
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
}



int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
    printMatrix(matrix);
    setMatrixZeroes(matrix);
    printMatrix(matrix);
    return 0;
} 



