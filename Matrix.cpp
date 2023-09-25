#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include<unordered_map>

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
/*
Median in a row-wise sorted Matrix
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.
*/

int median(vector<vector<int>> &matrix, int R, int C){
        // code here     
       int min_ele=INT_MAX;
       int max_ele=INT_MIN;
       int desired_count=(1+(R*C))/2;
       int mid=0,count=0;
       
       // Find the minimum and maximum elements in the matrix.
       for(int i=0; i<R; ++i) {
          
          min_ele=min(min_ele,matrix[i][0]);
          max_ele=max(max_ele,matrix[i][C-1]);
       }
       
       // Perform binary search between min_ele and max_ele to find the median.
       while(min_ele < max_ele) {
           
           mid=(min_ele+max_ele)/2;
           count=0;
           
           // Count how many elements in the matrix are less than or equal to mid
           for(int i=0; i<R; ++i) {
               
               count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
           }
           
           if(count<desired_count) 
                min_ele=mid+1;
           else
                max_ele=mid;
           
           
       }
       
       return min_ele;
    }
/*
Number of Palindromic paths in a Matrix
Given a matrix containing lower alphabetical characters only of size n*m.
We need to count the number of palindromic paths in the given matrix.
A path is defined as a sequence of cells starting from top-left cell and ending at bottom-right cell.
We are allowed to move to right and down only from current cell.
*/

long long int mod = 1000000007; // Modulus for handling large numbers.
unordered_map<string, long long int> umap; // Memoization cache using a map.

// Recursive function to count palindromic paths.
int count_paths(vector<vector<char>> matrix, int row1, int col1, int row2, int col2) {
    // Base cases:
    // 1. If either starting or ending positions go out of bounds, return 0.
    if (row1 >= matrix.size() || col1 >= matrix[0].size() || row2 < 0 || col2 < 0)
        return 0;
    
    // 2. If characters at corresponding positions are different, return 0.
    if (matrix[row1][col1] != matrix[row2][col2])
        return 0;
    
    // 3. If the positions coincide or are adjacent, return 1 (a palindrome path of length 1).
    if ((row1 == row2 && col1 == col2) || (abs(row1 - row2) + abs(col1 - col2)) <= 1)
        return 1;
    
    // 4. If (row1, col1) is beyond (row2, col2) in terms of row or column indices, return 0.
    if (row1 > row2 || col1 > col2)
        return 0;

    // Generate a unique key for memoization based on the starting and ending positions.
    string key = to_string(row1) + to_string(col1) + to_string(row2) + to_string(col2);
    
    // Check if the result for this key is already cached, and if so, return it.
    if (umap.find(key) != umap.end())
        return umap[key];

    // Recursively explore paths in four possible directions and memoize the result.
    long long path1 = count_paths(matrix, row1 + 1, col1, row2 - 1, col2) % mod;
    long long path2 = count_paths(matrix, row1 + 1, col1, row2, col2 - 1) % mod;
    long long path3 = count_paths(matrix, row1, col1 + 1, row2 - 1, col2) % mod;
    long long path4 = count_paths(matrix, row1, col1 + 1, row2, col2 - 1) % mod;

    // Store the result in the memoization cache.
    umap[key] = (path1 + path2 + path3 + path4) % mod;

    // Return the calculated result.
    return umap[key];
}

// Main function to count palindromic paths in the matrix.
int countPalindromicPaths(vector<vector<char>> matrix) {
    // Start counting palindromic paths from (0, 0) to the last cell in the matrix.
    return count_paths(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
}

int main() {
    // Test Case 1
    vector<vector<char>> matrix = {
        {'a', 'a', 'a', 'b'},
        {'b', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'}
    };

    int result = countPalindromicPaths(matrix);

    cout << "Number of palindromic paths: " << result << endl;

    return 0;
}



