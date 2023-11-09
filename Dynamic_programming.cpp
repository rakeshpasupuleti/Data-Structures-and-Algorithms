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



int main()
{

    return 0;
}