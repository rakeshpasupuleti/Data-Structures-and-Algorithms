#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <numeric>
#include <stack>

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


int main(){
    return 0;
}