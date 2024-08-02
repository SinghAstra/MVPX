#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(m*n)
// Space Complexity : O(m*n)
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> nums;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
        while (top <= bottom && left <= right) {
            for(int j = left; j <= right; j++){
                nums.push_back(matrix[top][j]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                nums.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
            for(int j = right; j>=left; j--){
                nums.push_back(matrix[bottom][j]);
            }
            bottom--;
            }
            if(left<=right){
            for(int i = bottom; i>=top; i--){
                nums.push_back(matrix[i][left]);
            }
            left++;
            }
        }
        return nums;
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

void printVector(vector<int> nums){
    int n = nums.size();
    cout << "Vector : ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}



int main(){
    vector<vector<int>> matrix = {{1,2,3,4,5},{16,17,18,19,6},{15,24,25,20,7},{14,23,22,21,8},{13,12,11,10,9}};
    vector<int> ans = spiralOrder(matrix);
    printVector(ans);
    return 0;
} 



