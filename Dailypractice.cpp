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
