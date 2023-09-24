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
/*
Search in a row-column sorted Matrix
Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x.
 Find whether element x is present in the matrix or not.
*/
bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here 
      if(n==0 or m==0)
        return -1;
      if(x<matrix[0][0] or x>matrix[n-1][m-1])
        return -1;
      
      int row=0,col=m-1;
      while(row<n and col>=0)
      {
          if(matrix[row][col]==x)
            return 1;
          else if(matrix[row][col]>x)
           col--;
          else
            row++;
      }
      return 0;
    }
/*
Maximum no of 1's row
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.
*/

int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            // your code here
            int result=-1,min_index=INT_MAX,temp_index=-1;
            
            for(int i=0; i<N; ++i) {
                
                temp_index = lower_bound(Mat[i].begin(), Mat[i].end(), 1) - Mat[i].begin();

                // Check if temp_index is valid (within bounds of the row)
                if(temp_index < M && temp_index < min_index ) {
                    
                    result=i;
                    min_index=temp_index;
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



