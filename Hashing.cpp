#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <numeric>

/*
First element to occur k times
Given an array of N integers. Find the first element that occurs at least K number of times.
*/
 int firstElementKTime(int a[], int n, int k)
    {
        unordered_map<int,int> umap;
        
        for(int i=0; i<n; ++i) {
            
            umap[a[i]]++;
            
            if(umap[a[i]]==k)
                return a[i];
        }
        
        return -1;
    }

/*

Number of pairs
Given two arrays X and Y of positive integers.
Find the number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.

*/
long long countPairs(int X[], int Y[], int M, int N)
    {
       //Your code here
       sort(X,X+M);
       sort(Y,Y+N);
       int zero=0;
       int one=0;
       int two=0;
       int ele,temp;
       long long result=0;
       for(int i=0;i<N;++i)
       {
            if(Y[i]==0)
                zero++;
            else if(Y[i]==1)
                one++;
            else if(Y[i]==2)
                two++;
       }
       for(int i=0;i<M;++i)
       {
          ele=X[i];
          if(ele==0)
            continue;
          else if(ele==1)
            result+=zero;
            else if(ele==2)
            {
                 temp=upper_bound(Y,Y+N,4)-Y;
                 if(temp!=N)
                    result+=N-temp;
                result=result+zero+one;
            }
            else if (ele==3)
            {
                temp=upper_bound(Y,Y+N,ele)-Y;
                 if(temp!=N)
                    result+=N-temp;
                result=result+zero+one+two;
            }
            else
            {
                temp=upper_bound(Y,Y+N,ele)-Y;
                 if(temp!=N)
                    result+=N-temp;
                result=result+zero+one;
            }
            
       }
       return result;
       
    }
/*

*/

/*
Find all pairs with a given sum
Given two unsorted arrays A of size N and B of size M of distinct elements.
The task is to find all pairs from both arrays whose sum is equal to X.

Note: All pairs should be printed in increasing order of u. For eg. for two pairs (u1,v1) and (u2,v2), if u1 < u2 then
(u1,v1) should be printed first else second.
*/

vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here   
        vector<pair<int,int>> result;
        unordered_map<int,int> umap;
        
        for(int i=0; i<M; ++i) umap[B[i]]++;
        
        sort(A,A+N);
        
        for(int i=0; i<N; ++i) {
            
            int diff=X-A[i];
            
            if(umap.find(diff)!=umap.end()) result.push_back({A[i],diff});
        }
        
        return result;
    }

/*
Common Elements
Given two lists V1 and V2 of sizes n and m respectively.
 Return the list of elements common to both the lists and return the list in sorted order. 
Duplicates may be there in the output list.
*/

vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        
        vector<int> result;
        unordered_map<int, int> umap;
        
        int n=v1.size();
        int m=v2.size();
        
        for(int i=0; i<n; ++i) {
            umap[v1[i]]++;
        }
        
        for(int i=0; i<m; ++i) {
            if(umap.find(v2[i])!=umap.end() && umap[v2[i]]>0) {
                result.push_back(v2[i]);
                umap[v2[i]]--;
            }
        }
        
        sort(result.begin(),result.end());
        
        return result;
    }

/*
Find All Four Sum Numbers
Given an array A of integers and another number K. 
Find all the unique quadruple from the given array that sums up to K.
Also note that all the quadruples which you return should be internally sorted, 
ie for any quadruple [q1, q2, q3, q4] the following should follow: q1 <= q2 <= q3 <= q4.
*/
vector<vector<int>> fourSum(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());

    vector<vector<int>> result;
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int target = k - (arr[i] + arr[j]);
            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum == target) {
                    result.push_back({arr[i], arr[j], arr[left], arr[right]});

                    // Move the left pointer to the right to skip duplicates
                    while (left < right && arr[left] == arr[left + 1]) {
                        left++;
                    }

                    // Move the right pointer to the left to skip duplicates
                    while (left < right && arr[right] == arr[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }

            while (j < n - 1 && arr[j] == arr[j + 1]) {
                j++;
            }
        }

        while (i < n - 1 && arr[i] == arr[i + 1]) {
            i++;
        }
    }

    return result;
}

/*
Count distinct elements in every window
Given an array of integers and a number K. 
Find the count of distinct elements in every window of size K in the array.
*/

vector<int> countDistinct(int A[], int n, int k) {
    
    unordered_map<int, int> umap;
    vector<int> result;
   
    int dist_count = 0;

    for (int i = 0; i < k; ++i) {
        // If the element A[i] is not found in the map, it's distinct. Increment dist_count.
        if (umap.find(A[i]) == umap.end())
            ++dist_count;
        
        ++umap[A[i]];
    }

    
    result.push_back(dist_count);

    // Slide the window and process the rest of the array.
    for (int win_end = k; win_end < n; ++win_end) {
        int win_start = win_end - k; // Calculate the start of the sliding window.

        // If the element leaving the window occurs only once, decrement dist_count.
        if (umap[A[win_start]] == 1)
            --dist_count;
        // Decrement the frequency of the element that's leaving the window.
        --umap[A[win_start]];

        // If the new element entering the window is not already in the map, it's distinct. Increment dist_count.
        if (umap[A[win_end]] == 0)
            ++dist_count;
        // Increment the frequency of the element that's entering the window.
        ++umap[A[win_end]];

        // Add the count of distinct elements in the current window to the result vector.
        result.push_back(dist_count);
    }

    
    return result;
}

/*
Array Pair Sum Divisibility Problem
Given an array of integers and a number k.
write a function that returns true if given array can be divided into pairs,
such that sum of every pair is divisible by k.
*/
 bool canPair(vector<int> nums, int k) {
    int freq[k] = {0};  

    for (auto ele : nums) {
         // Count the frequency of remainders when divided by 'k'.
        freq[ele % k]++; 
    }

    if (freq[0] % 2 == 1) {
        // If there are an odd number of elements with a remainder of 0, it's impossible to pair them.
        return false;
    }

    for (int i = 1; i < (k / 2) + 1; i++) {
        // Loop through the remaining remainders from 1 to k/2 and check for pairs.
        // If there's a remainder 'i', there should be an equal number of elements with remainder 'k - i'.
        if (freq[i] != freq[k - i]) {
            return false;
        }
    }

    return true;  // All elements can be paired as per the given conditions.
}

/*
Longest consecutive subsequence
Given an array of positive integers. 
Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers.
The consecutive numbers can be in any order.
*/

int findLongestConseqSubseq(int arr[], int N)
{
    unordered_map<int, int> umap;

    //  Store all array elements in the unordered_map
    for (int i = 0; i < N; ++i)
        umap[arr[i]] = 1;

    int seq_len = INT_MIN; 
    int temp_len = 0;
    
    for (int i = 0; i < N; ++i) {
        // Check if the current element is the start of a sequence
        if (umap.find(arr[i] - 1) == umap.end()) {
            temp_len = 1;
            int temp_var = arr[i] + 1;
            while (umap.find(temp_var) != umap.end()) {
                temp_len++;
                temp_var++;
            }
            seq_len = max(temp_len, seq_len);
        }
    }

    return seq_len;
}
/*
Array Subset of another array
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m.
Task is to check whether a2[] is a subset of a1[] or not.
Both the arrays can be sorted or unsorted. There can be duplicate elements.
*/
string isSubset(int a1[], int a2[], int n, int m) {
    // Check if array a2 is larger than array a1
    if (m > n) {
        return "No"; // If a2 is larger, it can't be a subset of a1
    }

    // Create an unordered map to count the occurrences of elements in a1
    unordered_map<int, int> umap;

    // Count the occurrences of each element in array a1
    for (int i = 0; i < n; ++i) {
        umap[a1[i]]++;
    }

    // Iterate through elements in a2 and check if they are present in a1 in sufficient quantities
    for (int i = 0; i < m; ++i) {
        if (--umap[a2[i]] < 0) {
            return "No"; // If a2 contains an element not present in a1, return "No"
        }
    }

    return "Yes"; // If all elements in a2 are found in a1, return "Yes"
}
/*
Zero Sum Subarrays
You are given an array arr[] of size n. 
Find the total count of sub-arrays having their sum equal to 0.
*/
long long int findSubarray(vector<long long int> &arr, int n ) {
    
    long long int count = 0;
    long long int curr_sum = 0;
    
   
    unordered_map<long long int, long long int> umap;
    
    
    for(int i = 0; i < n; ++i) {
        
        curr_sum += arr[i];
        
        // If the current sum is 0, increment the count as we've found a subarray with a sum of 0
        if(curr_sum == 0) {
            ++count;
        }
        
        // If the current sum has been seen before, update the count by the frequency of that sum
        if(umap.find(curr_sum) != umap.end()) {
            count += umap[curr_sum];
        }
        
        // Increment the frequency of the current sum in the map
        umap[curr_sum]++;
    }
    
    
    return count;
}
int main() {
    int arr[]={2,6,1,9,4,5,3};
    int N=7;
    int result=findLongestConseqSubseq(arr,N);
    cout<<"The out put is :"<<result<<endl;
    return 0;
}

