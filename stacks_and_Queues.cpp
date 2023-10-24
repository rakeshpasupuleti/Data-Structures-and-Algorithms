#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <numeric>
#include <stack>
#include<queue>

/*
Parenthesis Checker
Given an expression string x. 
Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".
*/

bool ispar(string X) {
    
    stack<char> mystack;

    
    for (char c : X) {
        // If the character is an open bracket, push it onto the stack.
        if (c == '[' || c == '{' || c == '(')
            mystack.push(c);
        else {
            // If the character is a closing bracket and the stack is empty,
            // it means there is no corresponding open bracket.
            if (mystack.empty())
                return false;

            // Pop the top element from the stack (which should be an open bracket).
            char top = mystack.top();
            mystack.pop();

            // Check if the closing bracket matches the last open bracket.
            if ((c == ']' && top != '[') || (c == '}' && top != '{') || (c == ')' && top != '('))
                return false;
        }
    }

    // After processing all characters, if the stack is empty, it means all brackets are balanced.
    return mystack.empty();
}

/*
Overlapping Intervals
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.
*/

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n <= 1) {
        return intervals;
    }

    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < n; ++i) {
        if (end >= intervals[i][0] ) {
            // Overlapping interval, update the end if needed
            end = max(end, intervals[i][1]);
        } else {
            // Non-overlapping interval, add the merged interval and reset start and end
            result.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // Add the last merged interval
    result.push_back({start, end});

    return result;
}

/*
Next Greater Element
Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.
*/

vector<long long> nextLargerElement(vector<long long> arr, int n) {
    
    vector<long long> result;
    stack<long long> mystack;

    // Iterate through the array in reverse order.
    for (int i = n - 1; i >= 0; --i) {
        // While the stack is not empty and the top element is less than or equal to the current array element, pop elements from the stack.
        while (!mystack.empty() && mystack.top() <= arr[i]) {
            mystack.pop();
        }
        
        // If the stack is empty, there's no larger element, so push -1 into the result vector.
        if (mystack.empty()) {
            result.push_back(-1);
        } else {
            // Otherwise, push the top element of the stack (which is the next larger element) into the result vector.
            result.push_back(mystack.top());
        }

        // Push the current array element into the stack for future comparisons.
        mystack.push(arr[i]);
    }

    // Reverse the result vector to get the elements in the correct order.
    reverse(result.begin(), result.end());

    // Return the result vector containing the next larger elements.
    return result;
}
/*
Stock span problem
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.
*/
vector<int> calculateSpan(int price[], int n)
{
    // Create a stack to store indices of prices in descending order.
    stack<int> mystack;

    // Create a vector to store the span values for each day.
    vector<int> result;

    // Iterate through the given array of prices for n days.
    for (int i = 0; i < n; ++i) {
        // While the stack is not empty and the price at the current day
        // is greater than or equal to the price at the top of the stack,
        // pop elements from the stack as they are no longer relevant.
        while (!mystack.empty() && price[mystack.top()] <= price[i])
            mystack.pop();

        // If the stack is empty, it means there is no greater price to the
        // left of the current day, so the span for this day is (i+1).
        if (mystack.empty())
            result.push_back(i + 1);
        else
            // If the stack is not empty, calculate the span by subtracting
            // the index at the top of the stack from the current index.
            result.push_back(i - mystack.top());

        // Push the current day's index onto the stack for future comparisons.
        mystack.push(i);
    }

    // Return the vector containing the span values for each day.
    return result;
}

/*
Implement Queue using two Stacks
Implement a Queue using 2 stacks s1 and s2 .
A Query Q is of 2 Types
(i) 1 x (a query of this type means  pushing 'x' into the queue)
(ii) 2   (a query of this type means to pop element from queue and print the poped element)

Note :- If there is no element return -1 as answer while popping.
*/
class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    int ele, temp;
    
    // Check if both stacks are empty, indicating that the queue is empty.
    if (s1.empty() && s2.empty()) {
        return -1;
    }
    
    // If s2 is empty, transfer elements from s1 to s2 for queue-like behavior.
    if (s2.empty()) {
        while (!s1.empty()) {
            temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
    }
    
    // Pop the front element from s2.
    ele = s2.top();
    s2.pop();
    
    return ele;
}


/*
Stack using two queues
Implement a Stack using two queues q1 and q2.
*/
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
// Function to push an element into the stack using two queues.
void QueueStack :: push(int x)
{
    // Enqueue the new element into the main queue (q1).
    q1.push(x);
}

// Function to pop an element from the stack using two queues.
int QueueStack :: pop()
{
    int top_element; // Variable to store the element to be popped.

    // Check if the stack is empty.
    if (q1.empty())
        return -1; // Stack is empty, return -1 or handle it as needed.

    // If the stack is not empty:
    
    // Move all but the last element from q1 to q2, maintaining the stack order.
    while (q1.size() > 1) {
        q2.push(q1.front()); // Enqueue the front element of q1 into q2.
        q1.pop(); // Dequeue the front element from q1.
    }

    // Get the top element from q1 (the element to be popped).
    top_element = q1.front();
    q1.pop();

    // Swap q1 and q2 so that q2 is now the empty queue.
    swap(q1, q2);

    return top_element; // Return the popped element.
}

/*
Get minimum element from stack
You are given N elements and your task is to Implement a Stack in which you can get a minimum element in O(1) time.
*/
class Solution{
    int minEle;           // Variable to keep track of the minimum element.
stack<int> s;         // Main stack to hold elements.

public:
    
   /* Returns the minimum element from the stack */
   int getMin(){
       if(s.empty())
        return -1;   // Handle the case when the stack is empty.

        return minEle;
   }

   /* Removes and returns the top element from the stack */
   int pop(){
       if(s.empty())
        return -1;   // Handle the case when the stack is empty.
        
       int ele = s.top();   // Get the top element from the stack.
       s.pop();             // Pop the top element from the stack.
       
       if (ele > minEle) 
       {
           return ele;   // If the popped element is greater than the minimum, return it.
       }
       else
       {
        int x = minEle;        // Backup the current minimum.
        minEle = 2 * minEle - ele;  // Calculate the previous minimum using the formula.
        return x;   // Return the original minimum value.
       }
   }

   /* Pushes the given element x into the stack */
   void push(int x){
       if(s.empty())
       {
           minEle = x;   // If the stack is empty, set x as the minimum and push it.
           s.push(x);
       }
       else
       {
           if(x > minEle)
            s.push(x);   // If x is greater than the minimum, push it directly.
           else
           {
               s.push(2 * x - minEle);  // If x is less than the minimum, push the modified value.
               minEle = x;              // Update the minimum to x.
           }
       }
   }

};

/*
Circular tour
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
*/
//Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n) {
    int total_petrol = 0;
    int total_distance = 0;
    int start_point = 0; // Initialize the starting point to 0.
    int rem_petrol = 0;  // Initialize remaining petrol to 0.

    for (int i = 0; i < n; ++i) {
        total_petrol += p[i].petrol;
        total_distance += p[i].distance;
        rem_petrol += p[i].petrol - p[i].distance;

        // If the remaining petrol is negative, we cannot start from the current station.
        // So, update the start point to the next station and reset remaining petrol.
        if (rem_petrol < 0) {
            start_point = i + 1;
            rem_petrol = 0;
        }
    }

    // If the total petrol is greater than or equal to the total distance, a tour is possible.
    if (total_petrol >= total_distance) {
        return start_point;
    } else {
        return -1;
    }
}

/*
First non-repeating character in a stream
Given an input stream A of n characters consisting only of lower case alphabets. 
While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. 
If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. 
If there is no such character then append '#' to the answer.

NOTE:
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every i you need to consider the string from starting position till ith position.
*/
string FirstNonRepeating(string A) {
    // Initialize a queue to maintain the order of characters.
    queue<char> myqueue;

    // Initialize an array to store the count of each character.
    int arr[26] = {0};

    // Initialize the result string to store the first non-repeating characters.
    string result;

    // Get the length of the input string.
    int len = A.size();

    // Iterate through the characters in the input string.
    for (int i = 0; i < len; ++i) {
        // Increment the count for the current character.
        arr[A[i] - 'a'] += 1;

        // Push the current character into the queue.
        myqueue.push(A[i]);

        // Check if there are repeating characters at the front of the queue
        // and remove them until the queue only contains non-repeating characters.
        while (!myqueue.empty() && arr[myqueue.front() - 'a'] > 1)
            myqueue.pop();

        // If the queue is empty, there are no non-repeating characters
        // in the current window, so add '#' to the result.
        if (myqueue.empty())
            result += '#';
        else
            // Otherwise, add the first non-repeating character to the result.
            result += myqueue.front();
    }

    // Return the final result containing the first non-repeating characters.
    return result;
}
/*
Rotten Oranges
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. 
A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 

*/

// Function to check if a given (row, col) position is within the grid bounds.
bool check_inbounds(int row, int col, int n, int m) {
    if (row < 0 || row >= n || col < 0 || col >= m)
        return false;
    return true;
}

// Main function to find the minimum time for all oranges to rot.
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();     // Number of rows in the grid.
    int m = grid[0].size();  // Number of columns in the grid.
    int time_to_rotten = 0;  // Time taken for all oranges to rot.
    int to_be_rotten = 0;    // Count of oranges that need to be rotten.

    queue<pair<int, int>> q;  // Queue to perform BFS traversal.

    // Direction vectors for moving in four directions: up, down, left, and right.
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    // Loop through the grid to count fresh and rotten oranges and initialize the queue.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1)
                to_be_rotten++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    // While there are fresh oranges and the queue is not empty, perform BFS.
    while (to_be_rotten > 0 && !q.empty()) {
        int len = q.size();  // Number of oranges in the current time step.
        for (int i = 0; i < len; ++i) {
            pair<int, int> temp = q.front();
            q.pop();

            // Check each of the four adjacent cells for fresh oranges.
            for (int d = 0; d < 4; ++d) {
                int newRow = temp.first + dx[d];
                int newCol = temp.second + dy[d];

                // Check if the new position is in bounds and contains a fresh orange.
                if (check_inbounds(newRow, newCol, n, m) && grid[newRow][newCol] == 1) {
                    --to_be_rotten;       // Decrease the count of fresh oranges.
                    grid[newRow][newCol] = 2;  // Mark the orange as rotten.
                    q.push({newRow, newCol});  // Add the rotten orange to the queue for the next round.
                }
            }
        }
        ++time_to_rotten;  // Increment the time step.
    }

    if (to_be_rotten > 0)
        return -1;          // Some oranges cannot rot (grid disconnected).
    else
        return time_to_rotten;  // Return the time taken for all oranges to rot.
}

/*
Maximum of all subarrays of size k
Given an array arr[] of size N and an integer K. 
Find the maximum for each and every contiguous subarray of size K.
*/
vector<int> max_of_subarrays(int *arr, int n, int k) {
    deque<int> dq;      // Initialize a deque to store indices of elements in the current subarray.
    vector<int> result; // Initialize a vector to store the maximum values of subarrays.

    // Process the first subarray of size k.
    for (int i = 0; i < k; ++i) {
        // Remove elements from the back of the deque if they are less than or equal to the current element.
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        // Append the index of the current element to the back of the deque.
        dq.push_back(i);
    }

    // Add the maximum element of the first subarray to the result.
    result.push_back(arr[dq.front()]);

    // Process subsequent subarrays of size k.
    for (int i = k; i < n; ++i) {
        // Remove elements from the front of the deque if they are outside the current subarray.
        while (!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();

        // Remove elements from the back of the deque if they are less than or equal to the current element.
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        // Append the index of the current element to the back of the deque.
        dq.push_back(i);

        // Add the maximum element of the current subarray to the result.
        result.push_back(arr[dq.front()]);
    }

    return result;
}

/*
Maximum Rectangular Area in a Histogram
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. 
For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.
*/
//Function to find largest rectangular area possible in a given histogram.
long long getMaxArea(long long arr[], int n)
{
    // Initialize a stack to keep track of indices of elements in the array.
    stack<int> s;
    
    // Create two vectors to store the indices of the nearest smaller elements on the left and right.
    vector<int> right;  // For the right side.
    vector<int> left;   // For the left side.
    
    // Initialize the left vector with -1 for the first element as there is no smaller element on the left.
    left.push_back(-1);
    
    // Push the index of the first element onto the stack.
    s.push(0);
    
    // Calculate the nearest smaller element on the left for each element.
    for(int i=1; i < n; i++)
    {
        // Pop elements from the stack until we find a smaller element or the stack is empty.
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        
        // If the stack is empty, there's no smaller element on the left, so add -1.
        if(s.empty())
            left.push_back(-1);
        else
            // Otherwise, add the index of the nearest smaller element.
            left.push_back(s.top());
            
        // Push the current element's index onto the stack.
        s.push(i);
    }
    
    // Clear the stack for the next iteration.
    while(!s.empty())
        s.pop();
    
    // Initialize the right vector with 'n' for the last element as there is no smaller element on the right.
    right.push_back(n);
    
    // Push the index of the last element onto the stack.
    s.push(n);
    
    // Calculate the nearest smaller element on the right for each element.
    for(int i = n - 1; i >= 0; i--)
    {
        // Pop elements from the stack until we find a smaller element or the stack is empty.
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        
        // If the stack is empty, there's no smaller element on the right, so add 'n'.
        if(s.empty())
            right.push_back(n);
        else
            // Otherwise, add the index of the nearest smaller element.
            right.push_back(s.top());
            
        // Push the current element's index onto the stack.
        s.push(i);
    }
    
    // Reverse the 'right' vector to make it correct for the final calculation.
    reverse(right.begin(), right.end());
    
    // Initialize variables for tracking the maximum area and a temporary area calculation.
    long long max_area = 0, temp;
    
    // Calculate the area for each element and find the maximum area.
    for(int i = 0; i < n; ++i)
    {
        temp = arr[i] * (right[i] - left[i] - 1);
        
        // Update the maximum area if the current area is larger.
        if(temp > max_area)
            max_area = temp;
    }
    
    // Return the maximum area found.
    return max_area;
}

int main(){
    return 0;
}