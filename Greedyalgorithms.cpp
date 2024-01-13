
#include<bits/stdc++.h>
using namespace std;

/*
Maximize Toys
Given an array arr[ ] of length N consisting cost of N toys and an integer K depicting the amount with you. 
Your task is to find maximum number of toys you can buy with K amount. 

*/

// Function to calculate the maximum number of toys that can be bought with a given budget K
int toyCount(int N, int K, vector<int> arr)
{
    // Initialize toy_count to keep track of the number of toys bought
    int toy_count = 0;

    // Sort the array in ascending order to prioritize buying cheaper toys first
    sort(arr.begin(), arr.end());

    // Iterate through the sorted array to select toys until the budget is exhausted
    for(int i = 0; i < N; ++i) {
        // Check if the current toy's price exceeds the remaining budget
        if(K < arr[i])
            return toy_count; // If so, return the current toy_count as it cannot be bought
        else 
            K -= arr[i]; // Subtract the cost of the current toy from the remaining budget
        ++toy_count; // Increment the toy_count as the toy has been successfully bought
    }

    // Return the final toy_count representing the maximum number of toys that can be bought
    return toy_count;
}


/*
Activity Selection
Given N activities with their start and finish day given in array start[ ] and end[ ]. 
Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.
*/
// Function to find the maximum number of non-overlapping activities that can be performed
int activitySelection(vector<int> start, vector<int> end, int n)
{
    // Priority queue to store activities sorted by their ending times
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // Variables to keep track of the current end time, count of selected activities,
    // and the start and end times of the current activity
    int end_time = INT_MIN, count = 0, curr_starttime = 0, curr_endtime = 0;

    // Insert activities into the priority queue with their ending times as the key
    // and starting times as the value
    for(int i = 0; i < n; ++i) {
        pq.push({end[i], start[i]});
    }

    // Process activities in ascending order of their ending times
    while(!pq.empty()) {
        // Get the next activity with the smallest ending time
        curr_endtime = pq.top().first;
        curr_starttime = pq.top().second;
        pq.pop();

        // If the current activity's starting time is greater than the previous activity's ending time,
        // select the current activity and update the end_time
        if(curr_starttime > end_time) {
            ++count;
            end_time = curr_endtime;
        }
    }

    // Return the count of selected non-overlapping activities
    return count;
}


/*

Choose and Swap
You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.
*/

// This function takes a string 'a' as input and returns a new string 
// where two characters are swapped in such a way that after swapping, 
// the resulting string is lexicographically smallest among all possible strings.

string chooseandswap(string a){
    
    // Initialize an array 'loc' to store the last index of each character in the string.
    int loc[26];
    
    // Initialize the 'loc' array with -1, indicating that no character has been encountered yet.
    for(int i=0; i<26; ++i) 
        loc[i]=-1;
    
    // Get the length of the input string.
    int len = a.length();
    
    // Traverse the input string to find the last occurrence of each character.
    for(int i=0; i<len; ++i) {
        if( loc[a[i]-'a']==-1)
            loc[a[i]-'a'] = i;
    }
    
    // Traverse the input string again to find the lexicographically smallest string 
    // by swapping characters if a smaller character is found later in the string.
    for( int i=0; i<len; ++i) {
        
        // Get the index of the current character in the 'loc' array.
        int x = a[i]-'a';
        
        // Iterate through characters smaller than the current character.
        for(int j=0; j<x; ++j) {
            
            // Check if a smaller character exists later in the string.
            if( loc[j]!=-1 && loc[j] > i) {
                
                // Swap the current character with the smaller character.
                char originalchar = a[i];
                char replacechar = char('a' +j); 
                
                // Initialize an empty string to store the result of the swap.
                string result="";
                
                // Iterate through the input string to perform the swap.
                for(int k=0; k<len; ++k) {
                    if(a[k]==originalchar)
                        result += replacechar;
                    else if(a[k]==replacechar)
                        result +=originalchar;
                    else
                        result +=a[k];
                }
                
                // Return the resulting string after the first successful swap.
                return result;
            }
        }
    }
    
    // If no swap is needed, return the original string.
    return a;
}
