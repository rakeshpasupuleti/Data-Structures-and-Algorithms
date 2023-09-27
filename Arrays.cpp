#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include<unordered_map>

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

int main() {

    return 0;
}