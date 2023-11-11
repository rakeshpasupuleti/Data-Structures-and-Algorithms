#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <numeric>

/*
Print all the subarrays of an array.
A subarray is  any contiguous part of a given array. 
The subarray has the same sequence of elements (order of the elements) as it is in the array.
*/
void generateSubArrays(int arr[], int n) {
    // Iterate through the starting index of subarrays
    for (int i = 0; i < n; i++) {
        // Iterate through the ending index of subarrays
        for (int j = 0; j < n && (i + j) < n; j++) {
            // Print the elements within the subarray
            for (int k = j; k <= (i + j); ++k) {
                cout << arr[k] << " ";
            }
            cout << endl; // Move to the next line for the next subarray
        }
    }
}


/*
Print All the subsets of th array
*/
// This function calculates all subsets of the input vector 'A' and stores them in 'res'.
// It uses recursion to generate subsets.
void calcSubset(vector<int>& A, vector<vector<int> >& res, vector<int>& subset, int index)
{
    // Add the current 'subset' to the result 'res'.
    res.push_back(subset);

    // Iterate through the elements of 'A' starting from the given 'index'.
    for (int i = index; i < A.size(); ++i) {
        // Include the current element in the 'subset'.
        subset.push_back(A[i]);

        // Recursively generate subsets with the current element included.
        calcSubset(A, res, subset, i + 1);

        // Backtrack: Remove the current element to explore other possibilities.
        subset.pop_back();
    }
}

// This function generates all subsets of the input vector 'A'.
vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;
    int index = 0;
    // Start the subset generation process.
    calcSubset(A, res, subset, index);
    return res;
}

/*
Print all the subsequences of the array elements 
*/
void generateSubsequences(int arr[], int index, vector<int> subarray, int n) {
   // Print the subsequences when we reach the end of recursion tree.
   if (index == n) {
      for (auto i : subarray)
         cout << i << " ";

      if (subarray.size() == 0)
         cout << "[]";
      cout << endl;
      return;
   }
   else {
      // adding the current index into the subsequence and calling the recursive function.
      subarray.push_back(arr[index]);

      generateSubsequences(arr, index + 1, subarray, n);

      // removing the added index into the subsequence.
      subarray.pop_back();

      // not adding the current element into the subsequence.
      generateSubsequences(arr, index + 1, subarray, n);
   }
}

/*
Leaders in an array
Write a program to print all the LEADERS in the array. 
An element is a leader if it is greater than all the elements to its right side. 
And the rightmost element is always a leader. 

*/
vector<int> leaders(int a[], int n){
        // Code here
        vector<int> result;
        int curr_leader=INT_MIN;
        
        for(int i=n-1; i>=0; --i) {
            
            if(a[i]>=curr_leader){
                curr_leader=a[i];
                result.push_back(curr_leader);
            }
        }
        
        reverse(result.begin(),result.end());
        return result;
}

/*
Equilibrium index of an array
Write a function that returns an equilibrium index (if any) or -1 if no equilibrium index.
The equilibrium index of an array is an index such that 
the sum of elements at lower indexes is equal to the sum of elements at higher indexes. 
*/

int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int right_sum=0,left_sum=0;
        
        for(int i=0; i<n; ++i) 
            right_sum+=a[i];
        
        for(int i=0; i<n; ++i) {
            
            right_sum-=a[i];
            
            if(right_sum==left_sum) return (i+1);
            
            left_sum+=a[i];
        }
        
        
        return -1;
    }

/*
Sort an array of 0s, 1s and 2s
Given an array A[] consisting of only 0s, 1s, and 2s.
The task is to write a function that sorts the given array.
*/
void sort012(int a[], int n)
    {
        // code here 
       
        int zeros,ones,twos,i;
        zeros=ones=twos=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
                zeros++;
            else if(a[i]==1)
                ones++;
            else
                twos++;
                
        }
        i=0;
        while(i<zeros)
        a[i++]=0;
        while(i<(zeros+ones))
        a[i++]=1;
        while(i<n)
        a[i++]=2;

    }

/*
Reverse an Array in groups of given size
Given an array arr[] and an integer K.
The task is to reverse every subarray formed by consecutive K elements.
*/
void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        int i;
        for(i=0;i<=n-k;i+=k)
        {
            reverse(arr.begin()+i,arr.begin()+i+k);
        }
        
        if(i<n-1)
        {
           reverse(arr.begin()+i,arr.end()); 
        }
    
    }

/*
Convert array into Zig-Zag fashion
Given an array of distinct elements of size N.
The task is to rearrange the elements of the array in a zig-zag fashion,
 so that the converted array should be in the below form:

 arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. 
*/
 void zigZag(int arr[], int n) {
        // code here
        
        for(int i=0;i<n-1;i++)
        {
            if(i%2==0 and arr[i]>arr[i+1])
            {
                swap(arr[i],arr[i+1]);
            }
            else if(i%2 !=0 and arr[i]<arr[i+1])
            {
                swap(arr[i],arr[i+1]);
            }
        }
        
    }
/*
Rearrange Array Alternately
Given a sorted array A[] consisting of N integers. 
The task is to rearrange the array alternatively i.e. 
the first element should be maxed value,second should be min value,
third should be the second max,fourth should be the second min, and so on.
*/
void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    int min_index=0,max_index=n-1,max_element=arr[n-1]+1,i;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            arr[i]+=arr[max_index]%max_element*max_element;
            max_index--;
        }
        else
        {
            
            arr[i]+=arr[min_index]%max_element*max_element;
            min_index++;
        }
    }
    for(i=0;i<n;i++)
    {
        arr[i]=arr[i]/max_element;
    }
    
    }

/*
Find the Missing Number in the Array
Given an array arr[] of size N-1 with integers in the range of [1, N].
The task is to find the missing number from the first N integers.
*/
int missingNumber(vector<int>& array, int n) {
        // Your code goes here
        int sum=n*(n+1)/2,curr_sum=0;
        for(int i=0;i<n-1;i++){
            curr_sum+=array[i];
        }
        return sum-curr_sum;
    }

/*
K-th Element of Two Sorted Arrays
Given two sorted arrays of size m and n respectively.
you are tasked with finding the element that would be at the k’th position of the final sorted array.
*/

int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m) return kthElement( arr2, arr1, m,  n,  k);
        
        
        int low=max(0,k-m), high=min(n,k);
        
        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=k-mid1;
            
            int l1= mid1==0 ? INT_MIN : arr1[mid1-1];
            int l2= mid2==0 ? INT_MIN : arr2[mid2-1];
            int r1= mid1==n ? INT_MAX : arr1[mid1];
            int r2= mid2==m ? INT_MAX : arr2[mid2];
       
            
        if(l1<=r2 and l2<=r1)  {
            
            return max(l1,l2);
        }
        
        else if(l1>r2)
        {
            high=mid1-1;
        }
        else  {
        
            low=mid1+1;
        }
        
        }
    
    
    }
/*
Check if two arrays are equal or not
Given two arrays, arr1 and arr2 of equal length N.
The task is to find if the given arrays are equal or not. 

Two arrays are said to be equal if:

both of them contain the same set of elements, 
arrangements (or permutations) of elements might/might not be same.
If there are repetitions, then counts of repeated elements must also be the same for two arrays to be equal.
*/

bool check(vector<int> A, vector<int> B, int N) {
        //code here
        unordered_map<int,int> umap;
        
        for(int i=0; i<N; ++i)  umap[A[i]]++;
        
        for(int i=0; i<N; ++i) {
            
            if(umap[B[i]]<=0)   return 0;
            --umap[B[i]];
        }
        
        
        return 1;
    }
/*
Largest Sum Contiguous Subarray (Kadane’s Algorithm)
Given an array arr[] of size N.
The task is to find the sum of the contiguous subarray within a arr[] with the largest sum. 
*/
long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long int max_so_far=INT_MIN,max_ending_here=0;
        
        for(int i=0; i<n; ++i) {
            
            max_ending_here+=arr[i];
            
            max_so_far=max(max_so_far,max_ending_here);
            
            if(max_ending_here<0)
                max_ending_here=0;
        }
        
        return max_so_far;
    }

/*
Find Subarray with given sum 
Given an array arr[] of non-negative integers and an integer sum.
find a subarray that adds to a given sum.
*/
 vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int start=0,end=0;
        long long sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            end=i;
           
            while(sum>s)    sum-=arr[start++];
           
             if(sum == s and sum!=0) return{start+1,end+1};
            
        }
        
        return {-1};
        
    }

/*
Trapping Rain Water
Given an array of N non-negative integers arr[] representing an elevation map where the width of each bar is 1.
compute how much water it is able to trap after raining.
*/
long long trappingWater(int arr[], int n){
        // code here
        long long int Total_trapped_water=0;
        int left_max_height[n];
        int right_max_height[n];
        
        left_max_height[0]=arr[0];
        for(int i=1;i<n;i++)
            left_max_height[i]=max(left_max_height[i-1],arr[i]);
        
        right_max_height[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            right_max_height[i]=max(right_max_height[i+1],arr[i]);
        
        int min_height;
        for(int i=0;i<n;i++)
        {
           min_height=min(left_max_height[i],right_max_height[i]);
            if(min_height>arr[i])
            {
                Total_trapped_water+=(min_height-arr[i]);
            }
            
        
            
        }
                
        return Total_trapped_water;
    }
/*
Minimum Number of Platforms Required for a Railway/Bus Station
Given the arrival and departure times of all trains that reach a railway station. 
The task is to find the minimum number of platforms required for the railway station so that no train waits.
*/

 int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int curr_platforms=0,max_platforms=0,i=0,j=0;
        sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	while(i<n)
    	{
    	    if(arr[i]<=dep[j])
    	    {
    	        ++curr_platforms;
    	        ++i;
    	    }
    	    
    	    else
    	    {
    	        --curr_platforms;
    	        ++j;
    	    }
    	    
    	    max_platforms=max(curr_platforms,max_platforms);
    	    
    	}
    	
    	return max_platforms;
    }
/*
Stock Buy Sell to Maximize Profit
The cost of a stock on each day is given in an array. Find the maximum profit that you can make by buying and selling on those days. 
If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.
*/
 vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        
        vector<vector<int> > result;
        int i=0,buy_day=0,sell_day=0;
        
        while(i<n) {
            
            while(i<n-1 && A[i]>=A[i+1])    ++i;
            if(i==n-1)  break;
            
            buy_day=i;
            ++i;
            
            while(i<n && A[i]>=A[i-1]) ++i;
                sell_day=i-1;
                
                result.push_back({buy_day,sell_day});
            
            
        }
        
        return result;
    }

/*
Largest number formed from an array
Given an array of numbers, arrange them in a way that yields the largest value. 
For example,if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}.
Then the arrangement 998764543431 gives the largest value.
*/
static int compare(string x1,string x2)
    {
        if((x1+x2) > (x2+x1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
	string printLargest(vector<string> &arr) {
	    
    int n=arr.size();
    string result="";
    sort(arr.begin(), arr.end(),compare);
    for(int i=0;i<n;i++)
    {
        result+=arr[i];
    }
    return result;
	}

/*
Find the length of largest subarray with 0 sum.
Given an array arr[] of length N, find the length of the longest sub-array with a sum equal to 0.
*/
int maxLen(vector<int>& A, int n)
{
    // Create an unordered map to store the cumulative sum and its index.
    unordered_map<int, int> umap;

    int curr_sum = 0; // Initialize the current cumulative sum to zero.
    int max_len = 0;  // Initialize the maximum length of subarray to zero.

    for (int i = 0; i < n; ++i) {
        curr_sum += A[i]; // Add the current element to the cumulative sum.

        // Check if the cumulative sum equals zero.
        if (curr_sum == 0)
            max_len = i + 1; // Update the maximum length if it's the longest so far.

        // Check if the current cumulative sum has been seen before.
        else if (umap.find(curr_sum) != umap.end())
            max_len = max(max_len, i - umap[curr_sum]); // Update max_len if needed.

        // Store the current cumulative sum and its index in the unordered map.
        else
            umap[curr_sum] = i;
    }

    return max_len; // Return the maximum length of subarray with zero sum.
}


/*
Find a pair of elements swapping which makes sum of two arrays same
Given two arrays of integers, find a pair of values (one value from each array) that you can swap to give the two arrays the same sum.
*/
int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        sort(A,A+n);
        sort(B,B+m);
        int Asum=0,Bsum=0,first=0,second=0,target;
        Asum = accumulate(A, A+n, Asum);
        Bsum = accumulate(B, B+m, Bsum);
        if((Asum-Bsum)%2!=0)
            return -1;
        else
        {
            target=(Asum-Bsum)/2;
        }
        while(first<n and second<m)
        {
            int temp=A[first]-B[second];
            if(temp==target)
                return 1;
            else if(temp<target)
                first++;
            else
                second++;
        }
        return -1;
        }

int main() {

    return 0;
}