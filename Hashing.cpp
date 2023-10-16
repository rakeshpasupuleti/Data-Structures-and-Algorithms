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


    

int main() {

    return 0;
}

