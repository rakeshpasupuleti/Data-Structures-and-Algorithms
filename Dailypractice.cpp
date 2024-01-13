#include<iostream>
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <numeric>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;

/*
JAN-06-2024
Techfest and the Queue
A Techfest is underway, and each participant is given a ticket with a unique number. 
Organizers decide to award prize points to everyone who has a ticket ID between a and b (inclusive). 
The points given to a participant with ticket number x will be the sum of powers of the prime factors of x.
For instance, if points are to be awarded to a participant with ticket number 12, the amount of points given out will be equal to the sum of powers in the prime factorization of 12 (22 × 31), which will be 2 + 1 = 3.
Given a and b, determine the sum of all the points that will be awarded to the participants with ticket numbers between a and b (inclusive).
*/

// Function to count the number of prime factors of a given number 'n'
int sumOfPowersOfPrime(int n) {
    // Initialize count to 0
    int count = 0;
    
    // Loop through potential prime factors up to the square root of 'n'
    for(int i=2; i<=sqrt(n); ++i) {
        // While 'i' is a factor of 'n', increment count and divide 'n' by 'i'
        while(n % i == 0) {
            ++count;
            n /= i;
        }
    }
    
    // If 'n' is greater than 1, it is a prime factor itself, so increment count
    if(n > 1)
        ++count;
    
    // Return the total count of prime factors for the given number 'n'
    return count;
}

// Main function to calculate the sum of prime powers for a range [a, b]
int sumOfPowers(int a, int b){
    // Initialize the result to 0
    int result = 0;
    
    // Loop through each number in the range [a, b]
    for(int idx=a; idx<=b; ++idx) {
        // Add the count of prime factors for the current number to the result
        result += sumOfPowersOfPrime(idx);
    }
    
    // Return the final result, which is the sum of prime powers for the given range
    return result;
}


/*
JAN-07-2024
Split Array Largest Sum
Given an array arr[] of N elements and a number K., split the given array into K subarrays such that the maximum subarray sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.

*/
// Function to find the minimum maximum sum of K non-overlapping subarrays
int splitArray(int arr[], int N, int K) {
    // Initialize low to the maximum element in the array
    int low = *max_element(arr, arr + N);
    
    // Initialize high to the sum of all elements in the array
    int high = accumulate(arr, arr + N, 0);
    
    // Initialize the result to the maximum element
    int result = low;

    // Binary search to find the minimum maximum sum
    while (low <= high) {
        // Calculate mid value for binary search
        int mid = (low + high) / 2;
        
        // Find the number of subarrays possible with a maximum sum less than or equal to mid
        int n = number_of_subarrays_possible(arr, N, mid);
        
        // Adjust the search space based on the number of subarrays
        if (n > K)
            low = mid + 1;
        else {
            // Update the result and narrow down the search space
            result = mid;
            high = mid - 1;
        }
    }
    
    // Return the minimum maximum sum of K non-overlapping subarrays
    return result;
}

// Function to find the number of subarrays with a maximum sum less than or equal to max_sum
int number_of_subarrays_possible(int arr[], int n, int max_sum) {
    int sum = 0, count = 1;
    
    // Iterate through the array to count the number of subarrays
    for (int i = 0; i < n; ++i) {
        // Check if adding the current element exceeds the maximum sum
        if (sum + arr[i] > max_sum) {
            // Start a new subarray with the current element
            sum = arr[i];
            ++count;
        } else {
            // Continue adding elements to the current subarray
            sum += arr[i];
        }
    }
    
    // Return the count of subarrays
    return count;
}


/*

JAN-08-2024
Merge 2 sorted linked list in reverse order.
Given two linked lists of size N and M, which are sorted in non-decreasing order. 
The task is to merge them in such a way that the resulting list is in non-increasing order.
*/
struct Node
{
    int data;
    Node* next;
};

// Merge two sorted linked lists and reverse the result
struct Node * mergeResult(Node *node1, Node *node2) {
    // If one list is NULL, return the reverse of the other list
    if (node1 == NULL)
        return reverse_linkedlist(node2);
    if (node2 == NULL)
        return reverse_linkedlist(node1);
    
    // Initialize pointers for the merged list
    Node *head = NULL;  // Head of the merged list
    Node *temp = NULL;  // Temporary pointer for traversing the merged list
    
    // Determine the initial head of the merged list based on the first nodes of node1 and node2
    if (node1->data < node2->data) {
        head = node1;
        node1 = node1->next;
    } else {
        head = node2;
        node2 = node2->next;
    }
    
    // Traverse both lists and merge them in sorted order
    temp = head;
    while (node1 && node2) {
        if (node1->data < node2->data) {
            temp->next = node1;
            temp = temp->next;
            node1 = node1->next;
        } else {
            temp->next = node2;
            temp = temp->next;
            node2 = node2->next;
        }
    }
    
    // Attach any remaining nodes in node1 and node2 to the merged list
    while (node1) {
        temp->next = node1;
        temp = temp->next;
        node1 = node1->next;
    }
    
    while (node2) {
        temp->next = node2;
        temp = temp->next;
        node2 = node2->next;
    }
    
    // Reverse the merged list
    head = reverse_linkedlist(head);
    
    // Return the head of the merged and reversed list
    return head;
}

// Reverse a linked list
Node * reverse_linkedlist(Node * head) {
    Node * prev = NULL;  // Previous node in the reversed list
    Node * curr = head;  // Current node being processed
    Node * next = NULL;  // Next node in the original list
    
    // Traverse the original list and reverse the links
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Return the new head of the reversed list
    return prev;
}


/*

09-JAN-2024
Search Pattern (KMP-Algorithm)
Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returing the indices. 
Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.
*/
//Own method
vector<int> search(string pat, string txt)
{
    // Initialize variables and data structures
    int n = txt.length();  // Length of the text
    int m = pat.length();  // Length of the pattern
    
    vector<int> result;  // Vector to store the positions where the pattern is found
    
    // Calculate the hash code for the pattern
    vector<int> enc_code(n, 0);
    int code = 0;
    for(int i=0; i<m; ++i) 
        code += int(pat[i]);
    
    // Calculate the hash code for the last character in the text
    enc_code[n-1] = int(txt[n-1]);
    
    // Calculate the cumulative hash codes for the characters in the text
    for(int i=n-2;  i>= n-m; --i)
        enc_code[i] = int(txt[i]) + enc_code[i+1];
    
    // Update the cumulative hash codes for the remaining characters in the text
    for(int i=n-m-1; i>=0; --i) {
        enc_code[i] = int(txt[i]) + enc_code[i+1] - int(txt[i+m]);
    }
    
    // Check for pattern matches in the text
    for(int i=0; i<=n-m; ++i) {
        // Check if the first and last characters of the pattern match the corresponding characters in the text
        if(txt[i]==pat[0]  && txt[i+m-1]==pat[m-1] && enc_code[i] == code) {
            // If the characters match, perform a character-wise check
            bool found = true;   
            for(int k=0; k<m; ++k) {
                if(txt[i+k] != pat[k])
                    found = false;
            }
            
            // If the pattern is found, add the position to the result vector
            if(found)   
                result.push_back(i+1);
        }
    }
    return result;  // Return the vector containing positions where the pattern is found
}


//Search Pattern (KMP-Algorithm)
vector<int> search(string pat, string txt)
{
    // Initialize variables and data structures
    int n = txt.length();  // Length of the text
    int m = pat.length();  // Length of the pattern
    vector<int> result;     // Vector to store the positions where the pattern is found
    vector<int> lps(m, 0);  // Longest Prefix Suffix array for the pattern
    
    int prevlps = 0, i = 1, j = 0;

    // Construct the Longest Prefix Suffix (LPS) array for the pattern
    while (i < m) {
        if (pat[i] == pat[prevlps]) {
            lps[i] = prevlps + 1;
            ++prevlps;
            ++i;
        } else if (prevlps == 0) {
            lps[i] = 0;
            ++i;
        } else {
            prevlps = lps[prevlps - 1];
        }
    }

    // Pattern matching using the LPS array
    i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            ++i;
            ++j;
        } else {
            if (j == 0) {
                ++i;
            } else {
                j = lps[j - 1];
            }
        }

        // Check if the entire pattern is found in the text
        if (j == m) {
            result.push_back(i - m + 1);  // Store the position of the pattern in the result vector
            j = lps[j - 1];  // Update j based on the LPS array
        }
    }

    return result;  // Return the vector containing positions where the pattern is found
}


/*
JAN-10-2024
Longest subarray with sum divisible by K
Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.
*/

int longSubarrWthSumDivByK(int arr[], int n, int k)
{
    // Create a hash table to store the remainder and its corresponding index
    unordered_map<int, int> mod_values;

    // Initialize variables for maximum length, current remainder, and current sum
    int max_len = 0, curr_mod = 0, curr_sum = 0;

    // Traverse the array
    for(int i = 0; i < n; ++i) {

        // Calculate the cumulative sum of the array elements
        curr_sum += arr[i];

        // Check if the current subarray sum is divisible by k
        if (curr_sum % k == 0)
            // If true, update max_len to the current index + 1
            max_len = i + 1;

        // Calculate the current remainder using modular arithmetic
        curr_mod = ((curr_sum % k) + k) % k;

        // Check if the current remainder is present in the hash table
        if (mod_values.find(curr_mod) != mod_values.end())
            // If true, update max_len with the maximum of its current value and the difference between the current index and the stored index for the same remainder
            max_len = max(max_len, i - mod_values[curr_mod]);
        else
            // If the current remainder is not present in the hash table, store it along with its index
            mod_values[curr_mod] = i;
    }

    // Return the maximum length of the subarray with a sum divisible by k
    return max_len;
}


/*
11-JAN-2024
Remove K Digits
Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.
*/
string removeKdigits(string S, int K) {
    // Stack to store characters during the first pass
    stack<char> st;
    // Stack to reverse the order of characters with leading zeros removed
    stack<char> st2;
    // Resulting string
    string result;

    // If no digits need to be removed, return the original string
    if (K == 0)
        return S;

    // If the length of the string is less than or equal to K, remove all digits and return "0"
    if (S.length() <= K)
        return "0";

    // First pass through the input string
    for (char x : S) {
        // While there are still digits to be removed, the stack is not empty, and the current digit is smaller than the top of the stack
        while (K > 0 && !st.empty() && st.top() > x) {
            // Pop the top of the stack and decrement K
            st.pop();
            --K;
        }
        // Push the current digit onto the stack
        st.push(x);
    }

    // Remove remaining digits if K is still greater than 0
    while (K > 0 && !st.empty()) {
        st.pop();
        --K;
    }

    // Reverse the order of characters in st and remove leading zeros
    while (!st.empty()) {
        st2.push(st.top());
        st.pop();
    }

    // Pop leading zeros from st2
    while (!st2.empty() && st2.top() == '0')
        st2.pop();

    // If st2 is empty after removing leading zeros, return "0"
    if (st2.empty())
        return "0";
    else {
        // Reconstruct the result by popping characters from st2
        while (!st2.empty()) {
            result += st2.top();
            st2.pop();
        }
    }

    // Return the final result
    return result;
}


/*
12-JAN-2024
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.
*/

// Function to reverse the first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // Create a stack to temporarily store the first k elements.
    stack<int> st;

    // Get the size of the queue.
    int n = q.size();

    // Push the first k elements of the queue onto the stack.
    for (int i = 0; i < k; ++i) {
        st.push(q.front());
        q.pop();
    }

    // Pop elements from the stack and enqueue them back to the queue.
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Move the remaining (n - k) elements from the front to the back of the queue.
    for (int i = k; i < n; ++i) {
        q.push(q.front());
        q.pop();
    }

    // Return the modified queue.
    return q;
}
