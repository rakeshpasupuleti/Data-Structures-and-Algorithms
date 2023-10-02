#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <numeric>

/*
Binary Search
Binary Search is defined as a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. 
The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(log N). 
*/

 int binarysearch(int arr[],int low,int high,int target)
   {
       if(low>high)
        return -1;
       
       int mid=(low+high)/2;
       if(arr[mid]==target)
        return mid;
       
       else if(arr[mid]>target)
        return binarysearch(arr,low,mid-1,target);
    
       else
            return binarysearch(arr,mid+1,high,target);
        
        
   }

/*
Quick Sort
Quick Sort is a Divide and Conquer algorithm. 
It picks an element as a pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position is low (the index of the array) 
and its ending position is high(the index of the array).
*/

static void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high)
        {
       int i=low-1;
       int pivot=arr[high];
       for(int j=low;j<=high-1;j++)
       {
           if(arr[j]<pivot)
           {
               i++;
               swap(arr[i],arr[j]);
           }
       }
       swap(arr[i+1],arr[high]);
       
            int pi=i+1;
            quickSort(arr,low,pi-1);
            quickSort(arr,pi+1,high);
        }
         
    }

/*
Merge Sort
Given an array arr[], its starting position l and its ending position r. 
Sort the array using merge sort algorithm.
*/

void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int n1=m-l+1;
         int n2=r-m;
         int i,k,j,left[n1],right[n2];
         for(int i=0;i<n1;i++)
         {
             left[i]=arr[l+i];
         }
         for(int i=0;i<n2;i++)
         {
             right[i]=arr[m+1+i];
         }
        i=0,j=0,k=l;
        while(i<n1 and j<n2)
        {
            if(left[i]<=right[j])
            {
                arr[k]=left[i];
                i++;
                k++;
            }
            else if(right[j]<left[i])
            {
                arr[k]=right[j];
                j++;
                k++;
            }
        }
            while(i<n1)
            {
                arr[k]=left[i];
                i++;
                k++;
            }
            while(j<n2)
            {
                arr[k]=right[j];
                j++;
                k++;
                
            }
        }
   
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)
        return;
        
        int mid=(l+r)/2;
        mergeSort( arr,  l, mid);
        mergeSort( arr,mid+1,r);
        merge( arr,  l, mid,r);
    }

/*
Merge two sorted arrays without using extra space

Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
 Merge them in sorted order without using any extra space. 
Modify arr1 so that it contains the first N elements 
and modify arr2 so that it contains the last M elements.
*/

 void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int i=0;
            int j=0;
            int k=n-1;
            while(i<=k and j<m)
            {
                if(arr1[i]<=arr2[j])
                {
                    i++;
                }
                else 
                {
                    swap(arr2[j],arr1[k]);
                    j++;
                    k--;
                }
                
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
/*
Sorting Elements of an Array by Frequency
Given an array A[] of integers, sort the array according to frequency of elements. 
That is elements that have higher frequency come first. 
If frequencies of two elements are same, then smaller number comes first.
*/

unordered_map<int, int> umap;

bool compare(int x, int y) {
    
    if (umap[x] != umap[y])
        return umap[x] > umap[y];
    else
        return x < y;
    
}

void sort_by_frequency(int arr[], int n) {
    umap.clear();
    for (int i = 0; i < n; ++i) umap[arr[i]]++;
    
    sort(arr, arr + n, compare);
    
}
/*
Search in a Rotated Array
Given a sorted and rotated array A of N distinct elements which is rotated at some point, 
and given an element key. The task is to find the index of the given element key in the array A. 
The whole array A is given as the range to search.

*/
int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(A[mid]==key)
                return mid;
            if(A[l]<=A[mid])
            {
                if(key<A[l] or key>A[mid])
                    l=mid+1;
                else
                    h=mid-1;
                    
            }
            else
            {
                if(key<A[mid] or key>A[h])
                    h=mid-1;
                else
                    l=mid+1;
            }
        }
        return -1;
    }
/*
Count Inversions
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

*/
long long merge(long long arr[], long long left,long long mid,long long right)
    {
        long long temp[right-left+1];
        int i=left;
        int j=mid;
        int k=0;
        long long count=0;
        while(i<mid and j<=right)
        {
            if(arr[i]<=arr[j])
            {
                temp[k]=arr[i];
                i++;
                k++;
            }
            else
            {
                temp[k]=arr[j];
                count+=mid-i;
                k++;
                j++;
                
            }
            
        }
        while(i<mid)
        {
            temp[k]=arr[i];
                i++;
                k++;
        }
        while(j<=right)
        {
            temp[k]=arr[j];
                k++;
                j++;
        }
        for(i=left,j=0;i<=right;i++,j++)
        {
            arr[i]=temp[j];
        }
        return count;
    }
    long long mergsort(long long arr[], long long left,long long right)
    {
        long long count=0;
        if(right>left)
        {
            int mid=(left+right)/2;
            count+=mergsort(arr,left,mid);
            count+=mergsort(arr,mid+1,right);
            count+=merge(arr,left,mid+1,right);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergsort(arr,0,N-1);
    }
/*
Sum of Middle Elements of two sorted arrays.
Given 2 sorted arrays Ar1 and Ar2 of size N each. 
Merge the given arrays and find the sum of the two middle elements of the merged array.
*/

int findMidSum(int arr1[], int arr2[], int N) {
            // code here 
        
        if(N==1) return arr1[0]+arr2[0];
        
        int low=0, high=N;
        
        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=N-mid1;
            
            int l1= mid1==0 ? INT_MIN : arr1[mid1-1];
            int l2= mid2==0 ? INT_MIN : arr2[mid2-1];
            int r1= mid1==N ? INT_MAX : arr1[mid1];
            int r2= mid2==N ? INT_MAX : arr2[mid2];
       
            
        if(l1<=r2 and l2<=r1)  {
            
            return max(l1,l2)+min(r1,r2);
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
Kth smallest element
Given an array arr[] and an integer K where K is smaller than size of array,
 The task is to find the Kth smallest element in the given array. 
 It is given that all array elements are distinct.
 Note :-  l and r denotes the starting and ending index of the array.
*/

int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        
        if(l<=r) {
            int pos=partition(arr,l,r);
            
                if(pos==k-1) {
                    return arr[k-1];
                }
                    
                else if(pos > k-1)
                    return  kthSmallest(arr,l,pos-1,k);
                    
                else
                    return  kthSmallest(arr,pos+1,r,k);
        }
        
        return -1;
    }
    
    
  int partition(int arr[], int low,int high) {
        int pivot=arr[high],i=low;
        
            
         for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            ++i;
        }
        
        
    }
    swap(arr[i], arr[high]);
        
        return i;
    }

/*

Allocate minimum number of pages
You have N books, each with A[i] number of pages.
M students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation 
where the student with the most books allocated to him gets the minimum number of pages, 
out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
*/
 bool ispossible(int A[],int N,int M ,int maxpages)
    {
        int stu=1,currpages=0;
        for(int i=0;i<N;i++)
        {
            if(A[i]>maxpages)
                return false;
            if(currpages+A[i]>maxpages)
                {
                    stu++;
                    if(stu>M)
                        return false;
                    currpages=A[i];
                }
            else
            {
                currpages+=A[i];
            }
            
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N)
            return -1;
        else if(M==1)
            return(accumulate(A,A+N,0));
        else if(M==N)
            return(*max_element(A,A+N));
        else
        {
            int l=*max_element(A,A+N);
            int h=accumulate(A,A+N,0);
            int mid,result=INT_MAX;
            while(l<=h)
            {
                mid=(l+h)/2;
                if(ispossible(A,N,M,mid))
                {
                    result=mid;
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
                
            }
            return result;
        }
        
    }

int main() {

    return 0;
}

