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



