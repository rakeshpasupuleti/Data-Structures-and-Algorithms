#include<iostream>
using namespace std;
#include<vector>

/*
Rotate matrix elements clockwise
Given two integers M, N, and a 2D matrix Mat of dimensions MxN, clockwise rotate the elements in it.
*/

vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
    int top = 0, bottom = M - 1, left = 0, right = N - 1;

    while (top < bottom && left < right) {
        int prev = Mat[top][left];

        // updating top row
        for (int i = left; i < right; ++i)
            swap(prev, Mat[top][i]);

        // updating rightmost col
        for (int i = top; i < bottom; ++i)
            swap(prev, Mat[i][right]);

        // updating bottom row
        for (int i = right; i > left; --i)
            swap(prev, Mat[bottom][i]);

        // updating leftmost col
        for (int i = bottom; i >=top; --i)
            swap(prev, Mat[i][left]);

        // updating dimensions of the matrix
        ++left;
        --right;
        ++top;
        --bottom;
    }

    return Mat;
}

/*
Spirally traversing a matrix
Given a matrix of size r*c. Traverse the matrix in spiral form.
*/

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> result;
        int top = 0, bottom = r - 1, left = 0, right = c - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse the top row
            for (int i = left; i <= right; ++i)
                result.push_back(matrix[top][i]);
            ++top;
            
            // Traverse the rightmost column
            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            --right;
            
            // Check if there is a bottom row to traverse
            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    result.push_back(matrix[bottom][i]);
                --bottom;
            }
            
            // Check if there is a leftmost column to traverse
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    result.push_back(matrix[i][left]);
                ++left;
            }
        }
        
        return result;
    }

    
int main() {
    // Test Case 1
    vector<vector<int>> a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> rotated = rotateMatrix(a.size(), a[0].size(), a);

    // Print the rotated matrix for testing
    for (int i = 0; i < rotated.size(); ++i) {
        for (int j = 0; j < rotated[i].size(); ++j) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



