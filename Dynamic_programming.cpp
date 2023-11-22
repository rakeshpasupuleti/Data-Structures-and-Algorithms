#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

/*
Minimum number of Coins
Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of coins required.
*/

vector<int> minPartition(int N)
{

    /* Using Dynamic 
    // Define an array of coin denominations in ascending order
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    // Create a vector to store the result, which will be the combination of coins used
    vector<int> result;

    // Calculate the number of elements in the 'coins' array
    int n = sizeof(coins) / sizeof(coins[0]);

    // Start a loop from the highest coin denomination to the lowest
    for (int i = n - 1; i >= 0; --i)
    {
        // Check if the remaining value 'N' is greater than or equal to the current coin
        while (N >= coins[i])
        {
            // If the condition is met, add the coin to the result vector and subtract its value from 'N'
            result.push_back(coins[i]);
            N = N - coins[i];
        }
    }

    // Return the result, which contains the combination of coins used to make up the original value
    return result;

    */

    
    
}

// using Dynamic programming


// Function to find the minimum number of coins required to make up a value 'V' using coin denominations in the 'coins' array
int minCoins(int coins[], int m, int V)
{
    // Create an array 'result' to store the minimum number of coins needed for values from 0 to 'V'
    int result[V + 1];

    // Initialize the minimum number of coins needed for value 0 as 0
    result[0] = 0;

    // Initialize all other values with a large integer value (INT_MAX) as a placeholder
    for (int i = 1; i <= V; i++)
        result[i] = INT_MAX;

    // Loop through each value from 1 to 'V'
    for (int i = 1; i <= V; i++) {
        // Loop through each coin denomination in the 'coins' array
        for (int j = 0; j < m; j++) {
            // Check if the current coin denomination can be used to make up the current value 'i'
            if (coins[j] <= i) {
                // Update the result for the current value 'i' with the minimum of the current result and
                // the result for the value 'i - coins[j]' incremented by 1
                result[i] = min(result[i], 1 + result[i - coins[j]]);
            }
        }
    }

    // If the result for the target value 'V' remains equal to INT_MAX, it means it is not possible to make 'V' with the given coins
    if (result[V] == INT_MAX)
        return -1;

    // Return the minimum number of coins required to make up the target value 'V'
    return result[V];
}

/*
Longest Common Substring
Given two strings. The task is to find the length of the longest common substring.
*/
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    // Create a 2D array 'lcss' to store the lengths of the longest common substrings
    int lcss[n + 1][m + 1];

    // Initialize the maximum length to 0
    int max_len = 0;

    // Initialize the 'lcss' array with 0s
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            lcss[i][j] = 0;
        }
    }

    // Iterate through the characters of both strings
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // Check if the current characters of both strings match
            if (S1[i - 1] == S2[j - 1]) {
                // If they match, update 'lcss' and compute the length of the common substring
                lcss[i][j] = 1 + lcss[i - 1][j - 1];
                // Update 'max_len' to store the maximum length found so far
                max_len = max(lcss[i][j], max_len);
            }
        }
    }

    // Return the length of the longest common substring
    return max_len;
}


//Recursive Approach

// Function to find the length of the longest common substring between two strings 'str1' and 'str2'
int solve(int i, int j, int count, string str1, string str2)
{
    // Base case: If either of the two strings has reached the beginning (i.e., i or j is 0),
    // return the current count as it represents the length of the common substring found so far.
    if (i == 0 || j == 0)
    {
        return count;
    }

    // If the characters at the current positions (i-1 and j-1) in both strings match,
    // continue the search by recursively calling the function with updated positions.
    if (str1[i - 1] == str2[j - 1])
    {
        count = solve(i - 1, j - 1, count + 1, str1, str2);
    }

    // Continue the search by recursively calling the function while ignoring one character from 'str2'.
    int count1 = solve(i, j - 1, 0, str1, str2);

    // Continue the search by recursively calling the function while ignoring one character from 'str1'.
    int count2 = solve(i - 1, j, 0, str1, str2);

    // Update 'count' to store the maximum of the three counts calculated:
    // 1. Count when matching characters are found.
    // 2. Count when one character from 'str2' is ignored.
    // 3. Count when one character from 'str1' is ignored.
    count = max({count, count1, count2});

    // Return the maximum count found, which represents the length of the longest common substring.
    return count;
}



/*
Longest Increasing Subsequence
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.
*/

//Using Dynamic Programming
int longestSubsequence(int n, int a[])
{
    // Create an array 'lss' to store the length of the longest increasing subsequence ending at each position
    int lss[n];
    
    // Initialize the maximum subsequence length to 1, as each element is a valid subsequence of length 1
    int max_seq = 1;

    // Iterate through the elements of the array
    for (int i = 0; i < n; ++i) {
        // Initialize the length of the subsequence ending at the current position to 1
        lss[i] = 1;
        
        // Compare the current element with previous elements to find the longest increasing subsequence
        for (int j = 0; j < i; ++j) {
            // If the current element is greater than the previous element and
            // extending the previous subsequence increases the length, update 'lss[i]'
            if (a[i] > a[j] && lss[i] < (lss[j] + 1)) {
                lss[i] = lss[j] + 1;
                // Update 'max_seq' to store the maximum subsequence length found so far
                max_seq = max(lss[i], max_seq);
            }
        }
    }

    // Return the maximum subsequence length found
    return max_seq;
}

//n*log(n) Approch
// Function to find the length of the longest increasing subsequence in an array 'a' of length 'n'
int longestSubsequence(int n, int a[])
{
    // Create a vector 'result' to store the elements of the increasing subsequence
    vector<int> result;
    
    // Initialize the maximum subsequence length to 1 and add the first element to 'result'
    int max_len = 1;
    result.push_back(a[0]);
    
    // Iterate through the elements of the array
    for (int i = 1; i < n; ++i) {
        // Check if the current element is greater than the last element in 'result'
        if (a[i] > result[max_len - 1]) {
            // If it is greater, add it to 'result' and increment the maximum subsequence length
            result.push_back(a[i]);
            ++max_len;
        } else {
            // If the current element is not greater, find the index where it could be inserted
            // using binary search (lower_bound) and update the value at that index in 'result'
            int idx = lower_bound(result.begin(), result.end(), a[i]) - result.begin();
            result[idx] = a[i];
        }
    }
    
    // Return the maximum subsequence length found
    return max_len;
}

/*
Longest Common Subsequence
Given two strings, find the length of longest subsequence present in both of them. 
Both the strings are in uppercase latin alphabets.
*/

int lcs(int n, int m, string s1, string s2) {
    // Create a 2D array to store LCS lengths for different substrings of s1 and s2.
    int lcs[n+1][m+1];

    // Initialize the array with zeros.
    for(int i=0; i<=n; ++i ) {
        for(int j=0; j<=m; ++j) {
            lcs[i][j]=0;
        }
    }

    // Compute LCS lengths for all possible substrings of s1 and s2.
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(s1[i-1] == s2[j-1]) {
                // If the characters at the current positions match, increment the LCS length.
                lcs[i][j] = 1 + lcs[i-1][j-1];
            } else {
                // If the characters don't match, take the maximum LCS length from the previous positions.
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
    }

    // The final element of the array contains the length of the LCS.
    return lcs[n][m];
}


/*
0 - 1 Knapsack Problem
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item or dont pick it (0-1 property).
*/

// Recursive method
int solveknapsack(int wt[], int val[], int W, int n, int index, int profit) {
    // Base case: If we've considered all items, return the current profit.
    if (index == n) {
        return profit;
    }
    // Check if the weight of the current item is less than or equal to the remaining capacity.
    if (wt[index] <= W) {
        // Calculate the maximum profit by either including or excluding the current item.
        // If included, subtract its weight and add its value to the profit.
        int wt_included_prft = solveknapsack(wt, val, W - wt[index], n, index + 1, profit + val[index]);
        // If not included, keep the same capacity and profit.
        int wt_not_included_prft = solveknapsack(wt, val, W, n, index + 1, profit);
        // Return the maximum profit of including or excluding the current item.
        return max(profit, max(wt_included_prft, wt_not_included_prft));
    } else {
        // If the weight of the current item is more than the remaining capacity, skip it.
        return solveknapsack(wt, val, W, n, index + 1, profit);
    }
}



//Using Dynamic programming

int knapSack(int maxCapacity, int weights[], int values[], int itemCount) {
    // Create a 2D array 'bag' to store maximum values for different capacities and items.
    vector<vector<int>> bag(itemCount + 1, vector<int>(maxCapacity + 1, 0));

    // Iterate through items.
    for (int itemIndex = 1; itemIndex <= itemCount; ++itemIndex) {
        // Iterate through capacities.
        for (int capacity = 1; capacity <= maxCapacity; ++capacity) {
            // Check if the weight of the current item can fit into the current capacity.
            if (capacity >= weights[itemIndex - 1]) {
                // Calculate the maximum value by either including or excluding the current item.
                // If included, add its value and consider the remaining capacity.
                int includeCurrentValue = values[itemIndex - 1] + bag[itemIndex - 1][capacity - weights[itemIndex - 1]];
                // If not included, keep the previous value for the same capacity.
                int excludeCurrentValue = bag[itemIndex - 1][capacity];
                // Store the maximum value in the 'bag' array.
                bag[itemIndex][capacity] = max(includeCurrentValue, excludeCurrentValue);
            } else {
                // If the weight of the current item is too large for the capacity, exclude it.
                bag[itemIndex][capacity] = bag[itemIndex - 1][capacity];
            }
        }
    }

    // The maximum value for the given capacity and items is stored in bag[itemCount][maxCapacity].
    return bag[itemCount][maxCapacity];
}


/*
Maximum sum increasing subsequence
Given an array of n positive integers. Find the sum of the maximum sum subsequence of the given array such that,
The integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.
*/
//Recursive Approch

int solvemaxsums(int arr[], int n, int prev_ele, int index, int result) {
    // Base case: if we have processed all elements, return the current result.
    if (index == n)
        return result;
    // Check if including the current element in the subsequence makes it strictly increasing.
    else if (arr[index] > prev_ele) {
        // Calculate the maximum sum by either including or excluding the current element.
        // If included, update prev_ele to the current element and move to the next index.
        int include_result = solvemaxsums(arr, n, arr[index], index + 1, (result + arr[index]));
        // If not included, keep the previous result and move to the next index.
        int excluded_result = solvemaxsums(arr, n, prev_ele, index + 1, result);

        // Return the maximum sum among including, excluding, and the previous result.
        return max(result, max(include_result, excluded_result));
    } else
        // If the current element cannot be included, move to the next index.
        return solvemaxsums(arr, n, prev_ele, index + 1, result);
}

int maxSumIS(int arr[], int n) {
    // Initialize the recursive function with the first index, INT_MIN as prev_ele, and 0 as result.
    int result = solvemaxsums(arr, n, INT_MIN, 0, 0);
    return result;
}

//Using Dynamic Programming

int maxSumIS(int arr[], int n) {
    
    // Create an array to store the maximum sum of increasing subsequences ending at each index
    int maxsubsums[n];
    
    // Initialize the result with the first element of the array
    int result = arr[0];
    
    // Initialize the maximum sum array with the values of the input array
    for(int i = 0; i < n; ++i)  {
        maxsubsums[i] = arr[i];
    }
    
    // Iterate over the array to find the maximum sum of increasing subsequences
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            
            // Check if the current element is greater than the previous elements
            if(arr[i] > arr[j]) {
                
                // Update the maximum sum ending at the current index
                maxsubsums[i] = max(maxsubsums[i], arr[i] + maxsubsums[j]);
            }
        }
        
        // Update the overall result with the maximum sum ending at the current index
        result = max(maxsubsums[i], result);
    }
    
    // Return the final result, which represents the maximum sum of increasing subsequences
    return result;
}

/*
Minimum number of jumps
Given an array of N integers arr[] where each element represents the maximum length of the jump that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

Note: Return -1 if you can't reach the end of the array.
*/
//Recursive Approch

int findminjumps(int arr[], int n, int index, int jumps) {
    // If the current index is beyond the end of the array, return the total number of jumps
    if (index >= n)
        return jumps;

    // If the value at the current index is 0, indicating no progress can be made, return -1
    if (arr[index] == 0)
        return -1;

    // Initialize result and temp to -1, indicating no valid jumps have been found yet
    int result = -1, temp = -1;

    // Explore all possible jumps from the current position
    for (int i = 1; i <= arr[index]; ++i) {
        // Recursive call to find the minimum jumps from the next position
        temp = findminjumps(arr, n, index + i, jumps + 1);

        // If a valid jump is found (temp != -1), update the result with the minimum value
        if (temp != -1) {
            if (result == -1)
                result = temp;
            else
                result = min(temp, result);
        }
    }

    // Return the result, which contains the minimum number of jumps needed to reach the end
    return result;
}


int minJumps(int arr[], int n) {
    // Initialize result with the result of the recursive function starting from index 0
    int result = findminjumps(arr, n, 0, 0);

    // Return the minimum number of jumps needed to reach the end of the array
    return result;
}


//Using Dinamic Programming
// Function to find the minimum number of jumps needed to reach the end of the array
// Parameters:
// - arr: The input array representing the maximum number of steps that can be taken from each position
// - n: Size of the array
int minJumps(int arr[], int n) {
    
    // Create an array to store the minimum number of jumps needed to reach each position
    int minjumps_to_reach[n];
    
    // Initialize the first element of the array (starting position) with 0 jumps
    minjumps_to_reach[0] = 0;
    
    // If the array is empty or the first element is 0, it's not possible to make any progress
    if (n == 0 || arr[0] == 0)
        return -1;
    
    // Iterate through the array to calculate the minimum jumps needed to reach each position
    for (int i = 1; i < n; ++i) {
        // Initialize the minimum jumps for the current position to the maximum possible value
        minjumps_to_reach[i] = INT_MAX;
        
        // Iterate through the positions before the current position
        for (int j = 0; j < i; ++j) {
            // Check if a jump from position j can reach or go beyond the current position i
            // and if the minimum jumps to reach position j is not the maximum possible value
            if (j + arr[j] >= i && minjumps_to_reach[j] != INT_MAX) {
                // Update the minimum jumps for position i with the minimum of its current value
                // and the jumps needed to reach position j plus one
                minjumps_to_reach[i] = min(minjumps_to_reach[i], minjumps_to_reach[j] + 1);
            }
        }
    }
    
    // If the minimum jumps for the last position is still the maximum possible value,
    // it means it's not possible to reach the end of the array
    if (minjumps_to_reach[n - 1] == INT_MAX)
        return -1;
    else
        // Return the minimum jumps needed to reach the end of the array
        return minjumps_to_reach[n - 1];
}

//Optimized algorithm

int minJumps(int arr[], int n) {
    // If the array has 0 or 1 elements, no jumps are needed
    if (n <= 1)
        return 0;

    // If the first element is 0, it's not possible to make any progress
    if (arr[0] == 0)
        return -1;

    // Initialize jumps to 0, max_reachable to 0, and curr_reach to 0
    int jumps = 0;
    int max_reachable = 0;
    int curr_reach = 0;

    // Iterate through the array to calculate the minimum jumps needed to reach the end
    for (int i = 0; i < n; ++i) {
        // If a jump from the current position i can reach or go beyond the end of the array
        if (i + arr[i] >= n - 1)
            return jumps + 1;

        // Update max_reachable with the maximum of its current value and the jump destination
        max_reachable = max(max_reachable, i + arr[i]);

        // If the current reach is equal to the current position i
        if (curr_reach == i) {
            // If max_reachable is less than or equal to i, it means no progress can be made
            if (max_reachable <= i)
                return -1;

            // Update the current reach to max_reachable and increment jumps
            curr_reach = max_reachable;
            ++jumps;
        }
    }

    return jumps;
}

/*
Edit Distance
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
*/

//Recursive method
    // Function to find the minimum number of replacements to convert string s to string t
int find_min_replacements(std::string &s, std::string &t, int n, int m) {
    // If the length of string s is 0, the number of replacements is equal to the length of string t
    if (n == 0)
        return m;
    
    // If the length of string t is 0, the number of replacements is equal to the length of string s
    if (m == 0)
        return n;

    // If the last characters of both strings are the same, no replacement is needed for the current characters
    if (s[n - 1] == t[m - 1])
        return find_min_replacements(s, t, n - 1, m - 1);
    else {
        // If the last characters are different, find the minimum of three possible operations:
        int result = 1 + std::min({
            find_min_replacements(s, t, n, m - 1),    // Insert a character in string s
            find_min_replacements(s, t, n - 1, m - 1), // Replace a character in string s
            find_min_replacements(s, t, n - 1, m)      // Delete a character from string s
        });

        return result;
    }
}

// Function to calculate the edit distance between two strings
int editDistance(std::string s, std::string t) {
    // Get the lengths of the input strings
    int n = s.length();
    int m = t.length();

    // Call the function to find the minimum replacements and return the result
    int result = find_min_replacements(s, t, n, m);
    return result;
}


//Using Dynamic programming 
// Function to calculate the edit distance between two strings using dynamic programming
int editDistance(std::string s, std::string t) {
    // Get the lengths of the input strings
    int n = s.length();
    int m = t.length();

    // Create a 2D array to store minimum replacements for substrings
    int minreplacements[n + 1][m + 1];

    // Loop through each combination of substrings of s and t
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            // If the length of string s is 0, the number of replacements is equal to the length of string t
            if (i == 0)
                minreplacements[i][j] = j;
            // If the length of string t is 0, the number of replacements is equal to the length of string s
            else if (j == 0)
                minreplacements[i][j] = i;
            // If the last characters of both substrings are the same, no replacement is needed for the current characters
            else if (s[i - 1] == t[j - 1])
                minreplacements[i][j] = minreplacements[i - 1][j - 1];
            else {
                // If the last characters are different, find the minimum of three possible operations:
                minreplacements[i][j] = 1 + min({
                    minreplacements[i - 1][j - 1], // Replace a character in string s
                    minreplacements[i][j - 1],     // Insert a character in string s
                    minreplacements[i - 1][j]      // Delete a character from string s
                });
            }
        }
    }

    // The final entry in the matrix contains the minimum replacements for the entire strings
    return minreplacements[n][m];
}

/*
Coin Change
Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum.
Find the number of ways you can make sum by using different combinations from coins[ ].  
Note: Assume that you have an infinite supply of each type of coin. 
And you can use any coin as many times as you want.


*/

long long int count(int coins[], int N, int sum) {

    // Array to store the number of ways to make each value from 0 to sum using given coins
    long long int num_ways[sum + 1];
    
    // Initialize the array with zeros
    fill(num_ways, num_ways + sum + 1, 0);
    
    // There is one way to make the sum of 0, which is by not selecting any coin
    num_ways[0] = 1;
    
    // Iterate through each coin
    for (int i = 0; i < N; ++i) {
        
        // Iterate through each value from coins[i] to sum
        for (int j = coins[i]; j <= sum; ++j) {
            
            // Update the number of ways to make value j by adding the ways to make (j - coins[i])
            // This is based on the principle of dynamic programming, building solutions for smaller subproblems
            num_ways[j] += num_ways[j - coins[i]];
        }
    }
    
    // The final result is stored in num_ways[sum], which represents the number of ways to make the given sum
    return num_ways[sum];
}


/*
Partition Equal Subset Sum
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
*/

//Using Recurssion
bool find_possibility(int arr[], int N, int idx, int sum, int target) {

    // Check if the current subset sum equals the target sum
    if (sum == target)
        return true;

    // Check if we have reached the end of the array without finding a subset
    if (idx == N)
        return false;

    // Initialize a boolean variable to track whether the current element is included in the subset
    bool included = false;

    // Check if including the current element in the subset is within the target sum
    if ((sum + arr[idx]) <= target)
        included = find_possibility(arr, N, idx + 1, sum + arr[idx], target);

    // Check for possibilities without including the current element in the subset
    bool excluded = find_possibility(arr, N, idx + 1, sum, target);

    // If either including or excluding the current element leads to a valid subset, return true
    if (included || excluded)
        return true;
    else
        return false;
}


//Using Dynamic Programming
int equalPartition(int N, int arr[]) {
    // Calculate the total sum of the array
    int sum = accumulate(arr, arr + N, 0);

    // Check if the sum is odd; if so, it cannot be divided into two equal partitions
    if (sum % 2 != 0) {
        return 0;
    }

    // Calculate the target sum for each partition
    int target = sum / 2;

    // Create a boolean array to track possible sums using dynamic programming
    vector<bool> dp(target + 1, false);

    // Initialization: an empty subset can achieve a sum of 0
    dp[0] = true;

    // Iterate through each element in the array
    for (int i = 0; i < N; ++i) {
        // Iterate through possible sums in reverse order to avoid using the same element multiple times
        for (int j = target; j >= arr[i]; --j) {
            // If the current element can be added to a subset with sum j, update dp[j]
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    // The final result is stored in dp[target], indicating whether a subset with sum target is possible
    return dp[target];
}

/*
Longest Palindrome in a String
Given a string S, find the longest palindromic substring in S. 
Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
Palindrome string: A string that reads the same backward. 
More formally, S is a palindrome if reverse(S) = S.
In case of conflict, return the substring which occurs first ( with the least starting index).
*/



// Function to find the length of a palindrome centered at given indices left and right
int palindrom_len(string s, int left, int right) {
    
    int n = s.size();
    
    // Expand around the center while the characters are equal and within bounds
    while (left >= 0 && right < n && s[left] == s[right]) {
        --left;
        ++right;
    }
    
    // Return the length of the palindrome found
    return (right - left - 1);
}

// Function to find the longest palindrome in a given string
string longestPalin(string S) {
    // Initialize the result string to store the longest palindrome found
    string result = "";
    
    // Get the length of the input string
    int n = S.size();
    
    // Iterate through each character in the string as a potential center of a palindrome
    for (int i = 0; i < n; ++i) {
        // Find the length of the palindrome when the center is a single character
        int len1 = palindrom_len(S, i, i);
        // Find the length of the palindrome when the center is between two characters
        int len2 = palindrom_len(S, i, i + 1);
        
        // Determine the maximum length among the two palindrome possibilities
        int max_len = max(len1, len2);

        // If the current palindrome is longer than the previously found one
        if (max_len > result.size()) {
            // Calculate the start and end indices of the palindrome
            int start = i - (max_len - 1) / 2;
            int end = i + max_len / 2;
            
            // Update the result string with the current palindrome
            result = S.substr(start, end - start + 1);
        }
    }
    
    // Return the longest palindrome found
    return result;
}

/*
Box Stacking
You are given a set of N types of rectangular 3-D boxes, 
where the ith box has height h, width w and length l. 
Your task is to create a stack of boxes which is as tall as possible,
but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. Your task is to complete the function maxHeight which returns the height of the highest possible stack so formed.
 

Note: 
Base of the lower box should be strictly larger than that of the new box we're going to place. This is in terms of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over the other.
*/

// Recursive function to find the maximum height of a stack of boxes
// Parameters:
//   - boxes: vector of vectors representing the dimensions of each box
//   - idx: current index of the box being considered
//   - prev_dim: dimensions of the box below the current one in the stack
//   - height: current height of the stack
int find_max_height(vector<vector<int>> &boxes, int idx, vector<int> prev_dim, int height) {
    // Base case: If all boxes have been considered, return the current height
    if (idx == -1)
        return height;

    // Recursive case:
    // Calculate the result excluding the current box
    int excluded_result = find_max_height(boxes, idx - 1, prev_dim, height);

    // Calculate the result including the current box if it can be stacked
    int included_result = 0;
    if (boxes[idx][0] > prev_dim[0] && boxes[idx][1] > prev_dim[1]) {
        // Create new dimensions for the current box and update the height
        vector<int> new_dim = {boxes[idx][0], boxes[idx][1], boxes[idx][2]};
        included_result = find_max_height(boxes, idx - 1, new_dim, height + boxes[idx][2]);
    }

    // Return the maximum of the excluded and included results
    return max(excluded_result, included_result);
}

// Static function used for sorting boxes based on their dimensions
 bool compare(vector<int> a, vector<int> b) {
    // Compare the dimensions of two boxes for sorting
    if (a[0] > b[0] && a[1] > b[1])
        return true;
    else
        return a[0] > b[0];
}

// Main function to calculate the maximum height of the stack of boxes
// Parameters:
//   - height, width, length: arrays representing the dimensions of the boxes
//   - n: number of boxes
int maxHeight(int height[], int width[], int length[], int n) {
    // Create a vector of vectors to store all possible box permutations
    vector<vector<int>> boxes;
    
    // Generate all possible permutations of box dimensions
    for (int i = 0; i < n; ++i) {
        // Create a vector representing the dimensions of the current box
        vector<int> dimensions = {length[i], width[i], height[i]};

        // Sort the dimensions for generating permutations
        sort(dimensions.begin(), dimensions.end());

        // Push the original dimensions into the boxes vector
        boxes.push_back(dimensions);

        // Generate permutations and push them into the boxes vector
        while (next_permutation(dimensions.begin(), dimensions.end())) {
            boxes.push_back(dimensions);
        }
    }

    // Sort the boxes vector based on the provided comparison function
    sort(boxes.begin(), boxes.end(), compare);

    // Initialize dimensions for the base box and call the recursive function
    vector<int> dim = {INT_MIN, INT_MIN, INT_MIN};
    int result = find_max_height(boxes, boxes.size() - 1, dim, 0);

    // Return the calculated result
    return result;
}

   // Comparison function to sort boxes in descending order based on dimensions
static bool compare(vector<int> a, vector<int> b) {
    // If both dimensions of box 'a' are greater than the corresponding dimensions of box 'b', return true
    if (a[0] > b[0] && a[1] > b[1])
        return true;
    // If only the first dimension of box 'a' is greater than the corresponding dimension of box 'b', return true
    else
        return a[0] > b[0];
}

//Dynamic Approach

// Function to calculate the maximum stack height of the boxes
int maxHeight(int height[], int width[], int length[], int n) {
    // Create a vector of vectors to store all permutations of box dimensions
    vector<vector<int>> boxes;

    // Generate all permutations of box dimensions and store them in the 'boxes' vector
    for (int i = 0; i < n; ++i) {
        vector<int> dimensions = {length[i], width[i], height[i]};
        // Sort the dimensions in ascending order to ensure consistency
        sort(dimensions.begin(), dimensions.end());
        boxes.push_back(dimensions);

        // Generate all permutations of the sorted dimensions and add them to the 'boxes' vector
        while (next_permutation(dimensions.begin(), dimensions.end())) {
            boxes.push_back(dimensions);
        }
    }

    // Sort the 'boxes' vector in descending order based on dimensions using the compare function
    sort(boxes.begin(), boxes.end(), compare);

    // Get the total number of permutations
    int m = boxes.size();

    // Create an array to store the maximum height for each box
    int max_height[m];

    // Initialize the result variable to store the maximum stack height
    int result = 0;

    // Set the initial height for each box
    for (int i = 0; i < m; ++i)
        max_height[i] = boxes[i][2];

    // Iterate through each box to find the maximum stack height
    for (int i = 1; i < m; ++i) {
        // Check all previous boxes to find the one on which the current box can be placed
        for (int j = 0; j < i; ++j) {
            // If the dimensions of the current box are strictly smaller than the dimensions of the previous box
            if (boxes[i][0] < boxes[j][0] && boxes[i][1] < boxes[j][1]) {
                // Update the maximum height for the current box
                max_height[i] = max(max_height[j] + boxes[i][2], max_height[i]);
            }
        }
        // Update the overall result with the maximum height of the current box
        result = max(result, max_height[i]);
    }

    // Return the final maximum stack height
    return result;
}



/*



*/
//Using Recurssion
int find_maxsegment_cut_recurssion(int n, int x, int y, int z) {
    // Base case: if n is negative, return a large negative value to indicate invalid cut
    if (n < 0)
        return INT_MIN;

    // Base case: if n is zero, no cuts needed, return 0
    if (n == 0)
        return 0;

    // Recursively calculate the maximum cuts for the current length using cuts of lengths x, y, and z
    int x_cut = find_maxsegment_cut_recurssion(n - x, x, y, z) + 1;
    int y_cut = find_maxsegment_cut_recurssion(n - y, x, y, z) + 1;
    int z_cut = find_maxsegment_cut_recurssion(n - z, x, y, z) + 1;

    // Return the maximum number of cuts for the current length
    return max({x_cut, y_cut, z_cut});
}

//Using memoization
// Function to find the maximum number of cuts of lengths x, y, and z from a given length n using memoization
int find_maxsegment_cut_memo(int n, int x, int y, int z, int memo[]) {
    // Base case: if n is negative, return a large negative value to indicate invalid cut
    if (n < 0)
        return INT_MIN;

    // Base case: if n is zero, no cuts needed, return 0
    if (n == 0)
        return 0;

    // Check if the result for the current length n is already memoized
    if (memo[n] != -1)
        return memo[n];

    // Recursively calculate the maximum cuts for the current length using cuts of lengths x, y, and z
    int x_cut = find_maxsegment_cut_memo(n - x, x, y, z, memo) + 1;
    int y_cut = find_maxsegment_cut_memo(n - y, x, y, z, memo) + 1;
    int z_cut = find_maxsegment_cut_memo(n - z, x, y, z, memo) + 1;

    // Store the maximum of the three cuts in the memo array for future reference
    memo[n] = max({x_cut, y_cut, z_cut});

    // Return the maximum number of cuts for the current length
    return memo[n];
}

// Function to maximize the number of cuts of lengths x, y, and z from a given length n
int maximizeTheCuts_memo(int n, int x, int y, int z) {
    // Create an array to memoize the results for each length from 0 to n
    int memo[n + 1];
    
    // Initialize the memo array with -1, indicating that no results are memoized yet
    fill(memo, memo + n + 1, -1);

    // Call the recursive function to find the maximum number of cuts
    int result = find_maxsegment_cut_memo(n, x, y, z, memo);

    // If the maximum number of cuts is still the initial value (INT_MIN), no valid cuts were made, so return 0.
    // Otherwise, return the maximum number of cuts.
    if (result < 0)
        return 0;
    else
        return result;
}


//Using Dynamic Programming
// Function to maximize the number of cuts of length x, y, and z from a given length n
int maximizeTheCuts(int n, int x, int y, int z) {
    // Create a vector to store the maximum number of cuts for each length from 0 to n
    vector<int> max_height(n + 1, INT_MIN);
    
    // Base case: no cuts needed for length 0
    max_height[0] = 0;

    // Loop through each length from 1 to n
    for (int i = 1; i <= n; ++i) {
        // Check if a cut of length x is possible
        if (i - x >= 0)
            // Update the maximum number of cuts for the current length using cut of length x
            max_height[i] = max(max_height[i], max_height[i - x] + 1);

        // Check if a cut of length y is possible
        if (i - y >= 0)
            // Update the maximum number of cuts for the current length using cut of length y
            max_height[i] = max(max_height[i], max_height[i - y] + 1);

        // Check if a cut of length z is possible
        if (i - z >= 0)
            // Update the maximum number of cuts for the current length using cut of length z
            max_height[i] = max(max_height[i], max_height[i - z] + 1);
    }

    // If the maximum number of cuts for the final length n is still the initial value (INT_MIN),
    // it means no valid cuts were made, so return 0. Otherwise, return the maximum number of cuts.
    if (max_height[n] < 0)
        return 0;
    else
        return max_height[n];
}

int main()
{

    return 0;
}