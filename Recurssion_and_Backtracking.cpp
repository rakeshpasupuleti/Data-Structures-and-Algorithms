
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

/*
Recursively remove all adjacent duplicates
Given a string s, remove all its adjacent duplicate characters recursively.

Note: For some test cases, the resultant string would be an empty string.
In that case, the function should return the empty string only.
*/

string remove_duplicates(string temp)
{
    int len = temp.size(); // Get the length of the input string.
    string res = "";       // Initialize an empty string to store the result.

    for (int idx = 0; idx < len; ++idx)
    { // Loop through the characters in the input string.
        if (idx < len - 1 && temp[idx] == temp[idx + 1])
        {                                                       // Check if the current character is the same as the next one.
            while (idx < len - 1 && temp[idx] == temp[idx + 1]) // If consecutive characters are the same, skip them.
                ++idx;
        }
        else
        {
            res += temp[idx]; // If the characters are different, add the current character to the result.
        }
    }

    return res; // Return the string with consecutive duplicates removed.
}

// This function 'rremove' takes a string 's' as input and repeatedly calls 'remove_duplicates' until no more consecutive duplicates are found.
string rremove(string s)
{
    string result;                 // Initialize a string to store the result.
    result = remove_duplicates(s); // Call 'remove_duplicates' to remove consecutive duplicates in the input.

    while (result.size() != s.size())
    {                                  // Continue removing duplicates until the result size matches the original size.
        s = result;                    // Update the input string with the result from the previous call.
        result = remove_duplicates(s); // Call 'remove_duplicates' again to further remove consecutive duplicates.
    }

    return result; // Return the final result with all consecutive duplicates removed.
}

/*
Tower Of Hanoi
The tower of Hanoi is a famous puzzle where we have three rods and N disks.
The objective of the puzzle is to move the entire stack to another rod.
You are given the number of discs N.
Initially, these discs are in the rod 1.
You need to print all the steps of discs movement so that all the discs reach the 3rd rod.
Also, you need to find the total moves.
Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N.
Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc.

*/

// This is a recursive function for solving the Tower of Hanoi problem.
// It's used to move N disks from the 'from' rod to the 'to' rod with the help of the 'aux' rod.
// N: Number of disks to be moved.
// from: Source rod from which disks are moved.
// to: Destination rod to which disks are moved.
// aux: Auxiliary rod used for temporary storage during the process.

long long toh(int N, int from, int to, int aux)
{
    if (N > 0)
    { // Base case: If there are disks to move.
        // Move N-1 disks from 'from' to 'aux', using 'to' as the auxiliary rod.
        toh(N - 1, from, aux, to);

        // Print the step to move the N-th disk from 'from' to 'to'.
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;

        // Move the N-1 disks from 'aux' to 'to', using 'from' as the auxiliary rod.
        toh(N - 1, aux, to, from);
    }

    // Calculate and return the total number of moves required for N disks.
    return pow(2, N) - 1;
}

/*
Special Keyboard
Imagine you have a special keyboard with the following keys:

Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

Find maximum numbers of A's that can be produced by pressing keys on the special keyboard N times.
*/

// Using Recursion
long long int optimalKeys(int N)
{
    if (N <= 6)
        return N; // Base case: If N is less than or equal to 6, return N.

    int max = 0; // Initialize a variable to keep track of the maximum result.

    for (int i = N - 3; i >= 1; i--)
    {
        // Iterate through previous values, going back 3 steps to find the optimal solution.

        int curr = (N - i - 1) * optimalKeys(i); // Calculate the current result based on recursive call to optimalKeys.

        if (curr > max)
        {
            max = curr; // Update the maximum result if the current calculation is greater.
        }
    }

    return max; // Return the maximum result found for N.
}

// Using DP
long long int optimalKeys(int N)
{

    if (N <= 6)
        return N;

    long long int result[N + 1] = {0}; // Initialize an array to store results, with all elements set to 0.

    long long ans = INT_MIN; // Initialize a variable to store the final result, starting with the minimum possible value.
    long long curr = 0;      // Initialize a variable to store the current calculation result.

    for (int i = 1; i < 7; ++i)
    {
        // For N less than or equal to 6, return N, which is the base case.
        result[i] = i; // Initialize results for i = 1 to 6 with their respective values.
    }

    for (int i = 7; i <= N; ++i)
    {
        // For N greater than 6, calculate the optimal result using dynamic programming.

        for (int j = i - 3; j >= 1; --j)
        {
            // Iterate through previous values, going back 3 steps to find the optimal solution.

            curr = (i - j - 1) * result[j]; // Calculate the current result.

            if (curr > result[i])
            {
                result[i] = curr; // Update the result for i if the current calculation is greater.
            }
        }
    }

    return result[N]; // Return the final result for N.
}

/*
Permutations of a given string
Given a string S.
The task is to print all unique permutations of the given string in lexicographically sorted order.
*/
void find_all_permutations(string s, int index, vector<string> &result, unordered_map<string, int> &umap)
{
    int len = s.size();

    if (index >= len)
    {
        // If we've reached the end of the string, check if the permutation is unique.
        if (umap.find(s) == umap.end())
        {
            result.push_back(s); // Add the unique permutation to the result vector.
        }
        umap[s]++; // Increment the count of this permutation in the unordered_map.
    }
    else
    {
        // If we haven't reached the end of the string, continue generating permutations.
        for (int i = index; i < len; ++i)
        {
            swap(s[index], s[i]);                              // Swap characters to generate a new permutation.
            find_all_permutations(s, index + 1, result, umap); // Recursively generate permutations.
            swap(s[i], s[index]);                              // Restore the string to its original state for the next iteration.
        }
    }
}

vector<string> find_permutation(string S)
{
    vector<string> result;                     // Initialize a vector to store the unique permutations.
    unordered_map<string, int> umap;           // Initialize an unordered_map to keep track of duplicate permutations.
    sort(S.begin(), S.end());                  // Sort the input string to ensure unique permutations.
    find_all_permutations(S, 0, result, umap); // Generate all permutations and store them in 'result'.

    return result; // Return the vector of unique permutations.
}

/*
N-Queen Problem
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle.
Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number.
For eg below figure represents a chessboard [3 1 4 2].
*/

bool is_valid_position(vector<vector<int>> board, int n, int row, int col)
{
    // Check for conflicts along horizontal and vertical lines.
    for (int i = 0; i < n; ++i)
    {
        if (board[row][i] == 1 || board[i][col] == 1)
            return false;
    }

    // Check for conflicts along the bottom-left to top-right diagonal.
    for (int i = row, j = col; i < n && j >= 0; ++i, --j)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check for conflicts along the top-left to bottom-right diagonal.
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Function to find all valid placements of queens on an NxN chessboard.
void find_nqueen_places(vector<vector<int>> board, int n, int col, vector<vector<int>> &result)
{
    if (col == n)
    {
        // If queens have been successfully placed in all columns, record the result.
        vector<int> ans;
        for (int column = 0; column < n; ++column)
        {
            for (int row = 0; row < n; ++row)
            {
                if (board[row][column] == 1)
                    ans.push_back(row + 1);
            }
        }
        result.push_back(ans);
    }
    else
    {
        // Try to place a queen in each row of the current column if it's a valid position.
        for (int row = 0; row < n; ++row)
        {
            if (is_valid_position(board, n, row, col))
            {
                // Place a queen in this position and recursively move to the next column.
                board[row][col] = 1;
                find_nqueen_places(board, n, col + 1, result);
                // Remove the queen from this position to explore other possibilities.
                board[row][col] = 0;
            }
        }
    }
}

// Function to find all solutions to the N-Queens problem for a given board size N.
vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize an empty chessboard.
    vector<vector<int>> result;                      // Store the results.

    // Start the recursive backtracking process to find valid queen placements.
    find_nqueen_places(board, n, 0, result);

    return result; // Return the list of valid queen placements.
}

/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task is to find a solved Sudoku.
For simplicity, you may assume that there will be only one unique solution.
A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Zeros in the grid indicates blanks, which are to be filled with some number between 1-9. You can not replace the element in the cell which is not blank.
*/
const int N = 9; // Define the size of the Sudoku grid.

bool is_valid_number(int grid[N][N], int row, int col, int num)
{
    // Check for conflicts in the same row and column.
    for (int i = 0; i < N; ++i)
    {
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
    }

    // Determine the top-left corner of the 3x3 subgrid containing the position.
    row = (row / 3) * 3;
    col = (col / 3) * 3;

    // Check for conflicts within the 3x3 subgrid.
    for (int i = row; i < row + 3; ++i)
    {
        for (int j = col; j < col + 3; ++j)
        {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using a backtracking approach.
bool SolveSudoku(int grid[N][N])
{
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            if (grid[row][col] == 0)
            {
                for (int val = 1; val <= 9; ++val)
                {
                    if (is_valid_number(grid, row, col, val))
                    {
                        // Try placing a valid number at the current position.
                        grid[row][col] = val;
                        bool possible = SolveSudoku(grid);

                        if (possible)
                        {
                            return true; // If the puzzle is solved, return true.
                        }
                        else
                        {
                            grid[row][col] = 0; // Backtrack: reset the cell if it leads to an invalid solution.
                        }
                    }
                }
                return false; // No valid number can be placed at this position; backtrack.
            }
        }
    }
    return true; // If the entire grid is filled, the Sudoku puzzle is solved.
}

// Function to print the Sudoku grid.
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << grid[i][j] << " ";
    }
}

/*
Rat in a Maze Problem - I
Consider a rat placed at (0, 0) in a square matrix of order N * N. 
It has to reach the destination at (N - 1, N - 1).
Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
*/

// Function to check if a move is possible from the current position (row, col)
bool is_possible_move(const vector<vector<int>> &m, int row, int col, int n)
{
    // Check if the move is within the bounds of the matrix and the cell is not blocked (m[row][col] == 0)
    if (row < 0 || row >= n || col < 0 || col >= n || m[row][col] == 0)
        return false;
    else
        return true;
}

// Function to find all possible paths from the starting point (0, 0) to the destination (n-1, n-1)
void find_all_possible_paths(vector<vector<int>> m, int row, int col, int n, vector<string> &result, string path)
{
    // Check if the current position is the destination
    if (row == n - 1 && col == n - 1)
    {
        result.push_back(path); // Add the path to the result
    }
    else
    {
        // Define possible moves (left, right, up, down)
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        char dr[] = {'L', 'R', 'U', 'D'};

        // Loop through the possible moves
        for (int i = 0; i < 4; ++i)
        {
            int new_row = row + dx[i];
            int new_col = col + dy[i];

            // Check if the move is possible
            if (is_possible_move(m, new_row, new_col, n))
            {
                m[new_row][new_col] = 0;                                               // Mark the cell as visited
                find_all_possible_paths(m, new_row, new_col, n, result, path + dr[i]); // Recursively explore the path
                m[new_row][new_col] = 1;                                               // Restore the cell after backtracking
            }
        }
    }
}

// Function to find all possible paths in the matrix
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> result;
    string path = "";

    // Check if the starting cell (0, 0) is open
    if (m[0][0] == 1)
    {
        m[0][0] = 0;                                       // Mark the starting cell as visited
        find_all_possible_paths(m, 0, 0, n, result, path); // Find all possible paths
    }

    // If no paths are found, add "-1" to the result
    if (result.empty())
        result.push_back("-1");

    return result; // Return the list of paths
}



/*
Word Boggle
Given a dictionary of distinct words and an M x N board where every cell has one character. 
Find all possible words from the dictionary that can be formed by a sequence of adjacent characters on the board. 
We can move to any of 8 adjacent characters

Note: While forming a word we can move to any of the 8 adjacent cells. 
A cell can be used only once in one word.
*/

// This function searches for a word in a 2D board of characters using a depth-first search approach.
// It checks if the characters in the board can be used to form the given word.
bool find_possible_word_path(vector<vector<char>>& board, vector<vector<int>>& check, int row, int col, int n, int m, string s, int index, vector<string>& result) {
    int len = s.size();

    // If we have successfully matched all characters in the word, add it to the result list and return true.
    if (index >= len) {
        result.push_back(s);
        return true;
    }

    char x = s[index];

    // Define possible moves in eight directions (up, down, left, right, and diagonals).
    int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    bool possible = false;

    // Iterate through all possible neighboring cells to find the next character in the word.
    for (int i = 0; i < 8; ++i) {
        int new_row = row + dr[i];
        int new_col = col + dc[i];

        // Check if the neighboring cell is within bounds, not visited before, and contains the required character.
        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && check[new_row][new_col] == 0 && board[new_row][new_col] == x) {
            // Mark the cell as visited.
            check[new_row][new_col] = 1;

            // Recursively search for the remaining characters in the word.
            possible = find_possible_word_path(board, check, new_row, new_col, n, m, s, index + 1, result);

            // Mark the cell as unvisited when returning from the recursive call.
            check[new_row][new_col] = 0;

            // If the word has been found, break out of the loop.
            if (possible)
                break;
        }
    }

    // Return whether it was possible to find the word.
    return possible;
}

// This function searches for words from a dictionary in a given Boggle board.
vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    int n = board.size();
    int m = board[0].size();
    
    vector<string> result;  // Store the words found in the board.
    vector<vector<int>> check(n, vector<int>(m, 0));  // A 2D array to keep track of visited cells.
    sort(dictionary.begin(), dictionary.end());  // Sort the dictionary to improve efficiency.
    
    // Iterate through each word in the dictionary and try to find it in the board.
    for (auto s : dictionary) {
        char start = s[0];
        bool possible = false;

        // Iterate through each cell in the board to start searching for the word.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == start) {
                    // Mark the starting cell as visited.
                    check[i][j] = 1;

                    // Search for the rest of the characters in the word using the find_possible_word_path function.
                    possible = find_possible_word_path(board, check, i, j, n, m, s, 1, result);

                    // Mark the starting cell as unvisited.
                    check[i][j] = 0;

                    // If the word has been found, break out of the loop.
                    if (possible)
                        break;
                }
            }

            // If the word has been found, break out of the loop.
            if (possible)
                break;
        }
    }

    // Return the list of words found in the Boggle board.
    return result;
}


/*
Generate IP Addresses
Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.


For string 11211 the IP address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1
*/

// This function checks if a given string is a valid component of an IPv4 address.
bool isvalid_string(string s) {
    int n = s.length();

    // Check if the string is empty, longer than 3 characters, or starts with '0' and has more than one character.
    if (n == 0 || n > 3 || (s[0] == '0' && n > 1)) 
        return false;

    // Convert the string to an integer to check if it's in the valid range [0, 255].
    int temp = stoi(s);

    if (temp < 0 || temp > 255)
        return false;

    return true;
}

// This function generates valid IPv4 addresses from a given input string.
vector<string> genIp(string &s) {
    vector<string> result;

    int len = s.size();

    // Iterate through possible combinations of four components of an IPv4 address.
    for (int i = 1; i < len - 2; ++i) {
        for (int j = i + 1; j < len - 1; ++j) {
            for (int k = j + 1; k < len; ++k) {
                // Extract substrings to form the four components.
                string part1 = s.substr(0, i);
                string part2 = s.substr(i, j - i);
                string part3 = s.substr(j, k - j);
                string part4 = s.substr(k, len);

                // Check if all four components are valid and, if so, add them to the result vector as an IPv4 address.
                if (isvalid_string(part1) && isvalid_string(part2) && isvalid_string(part3) && isvalid_string(part4))
                    result.push_back(part1 + '.' + part2 + '.' + part3 + '.' + part4);
            }
        }
    }

    // If no valid IPv4 addresses were found, add "-1" to the result.
    if (result.empty())
        result.push_back("-1");

    return result;
}
