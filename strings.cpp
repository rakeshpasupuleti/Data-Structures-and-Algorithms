#include <iostream>
#include <string>
#include<unordered_map>
#include<vector>
using namespace std;
/*
Reverse words in a given string
Given a String S, reverse the string without reversing its individual words.
 Words are separated by dots.
*/
void helper_rev(string & str,int start,int end) {
        
        while(start<end) {
            swap(str[start],str[end]);
            ++start;
            --end;
        }
    }
string reverseWords(string S) 
    { 
       
        int start=0,end=0,index=0,len=S.length();
      helper_rev(S,0,len-1);
        
        while(index<len) {
            
            if(S[index]=='.') {
                end=index-1;
                helper_rev(S,start,end);
                start=index+1;
            }
            
            ++index;
        }
        
        if(start!= len-1) helper_rev(S,start,len-1);
        
        
        return S;
    
    // //Method 2
    // string result="",temp_str="";
    // int index=S.lenght()-1;
    // while(index>0) {
        
    //     if(S[index]=='.') {
    //         temp_str=S[i]+temp_str;
    //     }
    //     else {
    //         result=result+temp_str+S[i];
    //         temp_str="";
    //     }
        
    // }
    
    // return result;
    } 


/*Given two strings a and b. The task is to find 
if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places.*/
 bool isRotated(string str1, string str2)
    {
        // Your code here
        int n=str1.length();
        int m=str2.length();
        bool clockwise=true,anti_clockwise=true;
       
      if(n!=m)
        return false;
      
        // check for clockwise 
        for(int i=0;i< n; ++i ) {
               if(str1[i]!=str2[(i+2)%n]) {
                   clockwise=false;
                   break;
               }
        }
        
        // check for Anticlockwise 
        for(int i=0;i< n; ++i ) {
               if(str1[(i+2)%n]!=str2[i]) {
                   anti_clockwise=false;
                   break;
               }
        }
            
     return (clockwise || anti_clockwise);
           
    }

/*
Given a string in roman no format (s)  your task is to convert it to an integer . 
Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000
*/
     int romanToDecimal(string &str) {
        // code here
        int num=0;
        unordered_map<char,int>umap;
        umap['I']=1;
        umap['V']=5;
        umap['X']=10;
        umap['L']=50;
        umap['C']=100;
        umap['D']=500;
        umap['M']=1000;
        
        int index=str.length()-1;
        // num+=umap[str[index]];
        // --index;
        while(index>=0) {
            
            if( umap[str[index]] >= umap[str[index+1]] )
                num+=umap[str[index]];
            else num-=umap[str[index]];
            
            --index;
        }
        
        return  num;
    }
/*
Anagram
An anagram of a string is another string that contains the same characters,
 only the order of characters can be different.
*/
bool isAnagram(string a, string b){
        
        // Your code here
       int arr[256]={0};
       for(int i=0; a[i] ; ++i) {
           arr[a[i]]++;
       }
       
       for(int i=0; b[i]; ++i) {
           arr[b[i]]--;
           if(arr[b[i]]<0)  return false;
       }
       
       return true;
        
    }
/*
Remove Duplicates
Given a string without spaces, the task is to remove duplicates from it.

Note: The original order of characters must be kept the same.
*/
string removeDups(string S) 
	{
	    // Your code goes here
	    int arr[256]={0};
	    int idx=0;
	    string result="";
	    for(int i=0; S[i] ; ++i) {
	        if(arr[S[i]]==0) {
	            result+=S[i];
	            arr[S[i]]++;
	            
	        }
	        
	    }
	    return result;
	}
/*
Longest Distinct characters in string
Given a string S, find the length of the longest substring with all distinct characters. 
*/

int longestSubstrDistinctChars (string S)
{
    // your code here
    int n=S.length();
    if(n<=1)
        return n;
    
    int result=0,left=0,right=0;
    bool visited[256]={false};
    for (; right < n;++right)
    {
        if (visited[S[right]] == false)
            visited[S[right]] = true;
        else
        {
            result=max(result,right-left);
            while (left < right) {
                if (S[left] != S[right])
                    visited[S[left]] = false;
                else {
                    left++;
                    break;
                }
                left++;
            }
        }
    }
    result=max(result,right-left);
    
    return result;     
    
}

/*
Implement Atoi
Your task  is to implement the function atoi.
 The function takes a string(str) as argument and converts it to an integer and returns it.

*/

    int atoi(string str) {
        //Your code here
        int result=0,neg=0;
        int i=0;
        
        if(str[i]=='-') {
            neg=1;
            ++i;
        }
        
        for(; str[i]!= '\0'; ++i) {
            
            if(str[i]>='0' and str[i]<='9'){
                result=result*10+str[i]-48;
            }
            else {
                return -1;
            }
        }
        
        if(neg) {
            result*=-1;
        }
        
        
        return result;
    }
/*
Implement strstr
Your task is to implement the function strstr.
 The function takes two strings as arguments (s,x) and  
 locates the occurrence of the string x in the string s.
 The function returns an integer denoting the first occurrence of the string x in s (0 based indexing).
*/

int strstr(string s, string x)
{
     //Your code here
    bool flag=false;
    int len=s.length();
    for(int i=0; i<len ; ++i )
    {
        if(s[i]==x[0]) {
            flag=true;
            for(int j=0; x[j]!='\0'; ++j) {
                if((i+j)<=len && s[i+j]==x[j]) {
                    continue;
                }
                
                else {
                    flag=false;
                }
            }
        }
        
        if(flag==true) 
            return i;
    }
    
    return -1;
}

/*
Search Pattern (Rabin-Karp Algorithm)
Given two strings, one is a text string and other is a pattern string. 
The task is to print the indexes of all the occurences of pattern string in the text string. 
For printing, Starting Index of a string should be taken as 1.
*/
vector <int> search(string pat, string txt)
        {
            //code here.
            vector<int> result;
            bool flag=false;
            int n=txt.length();
            int m=pat.length();
            for(int i=0; i<=n-m ; ++i )
            {
                if(txt[i]==pat[0] && (i+m)<=n && txt[i+m-1]==pat[m-1]  ) {
                    flag=true;
                    for(int j=0; pat[j]!='\0'; ++j) {
                        if( txt[i+j]==pat[j]) {
                            continue;
                        }
                        
                        else {
                            flag=false;
                        }
                    }
                }
                
                if(flag==true) {
                    result.push_back(i+1);
                    flag=false;
                }
                    
            }
            
           if(result.empty()) 
                result.push_back(-1);
                
                
           return result;
        }

/*
Longest Prefix Suffix
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.
*/

int lps(string s) {
	    // Your code goes here
	    int result=0,n=s.length();
	    
	    for(int i=1; i<=n; ++i) {
	        
	        if(s[i]==s[0] && s[n-i-1]==s[n-1]) {
	
	           int count=0,j=i,k=0;
	            while(j < n && s[j]==s[k]) {
	                ++count;
	                ++j;
	                ++k;
	            }
	            
	            if(j==n) {
	                result=max(result,count);
	                break;
	            }	           
	        }
	    }
	    
	    return result;
	}

/*
Minimum indexed character
Given a string str and another string patt. 
Find the minimum index of the character in str that is also present in patt.


*/

int minIndexChar(string str, string patt)
    {
        // Your code here
        int arr[256]={0};
        int n=str.length();
        int m=patt.length();
        
        for(int i=0 ; i<m ; ++i) {
            arr[patt[i]]++;
        }
        
        for(int i=0 ; i<n ; ++i) {
            if(arr[str[i]]) {
                return i;
            }
        }
        
        return -1;
    }
/*
Convert a sentence into its equivalent mobile numeric keypad sequence.\
Given a sentence in the form of a string in uppercase, convert it into its equivalent mobile numeric keypad sequence.
Please note there might be spaces in between the words in a sentence and we can print spaces by pressing 0.
*/
    string printSequence(string S)
        {
            //code here.
            
            string result;
            string values[] = {
                "2", "22", "222", "3", "33",
                "333", "4", "44", "444", "5",
                "55", "555", "6", "66", "666",
                "7", "77", "777", "7777", "8",
                "88", "888", "9", "99", "999",
                "9999"
            };
            
            for(int i=0; S[i]!='\0'; ++i) {
                
            if(S[i]==' ')
                result+="0";
            else 
                result+=values[S[i]-'A'];
                
            }
            
            return result;
            
        }
/*
Longest Common Prefix in an Array
Given an array of N strings, find the longest common prefix among all strings present in the array.
*/

string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string result="";
        char test;
        int idx=0;
        
        while(1) {
            
            for(int i=0; i< N ;++i) {
                
                if( arr[i][idx]=='\0' || arr[i][idx]!=arr[0][idx]) {
                  
                  if(result.empty()) 
                        result+="-1";
                        
                    return result;
                }
                
            }
            
            result+=arr[0][idx];
            ++idx;
        }
        
        if(result.empty()) 
            result+="-1";
            
        return result;
    }
/*
Uncommon characters
Given two strings A and B consisting of lowercase english characters. 
Find the characters that are not common in the two strings. 

Note :- Return the string in sorted order.
*/

string UncommonChars(string A, string B)
        {
            // code here
            int freq[26]={0};
            
            string result;
            for(int i=0; A[i]!='\0' ;++i)
                freq[A[i]-'a']=1;
            
            for(int i=0;B[i]!='\0' ;++i)
                if(freq[B[i]-'a']==1 or freq[B[i]-'a']==-1 )
                    freq[B[i]-'a']=-1;
                else
                    freq[B[i]-'a']=2;
                    
            
            for(int i=0;i<26;++i)
                if(freq[i]==1 or freq[i]==2)
                {
                    result+=char(i+'a');
                }
            
            if(result.empty())
                return "-1";
            else
                return result;
            
        }
/*
Smallest window in a string containing all the characters of another string
Given two strings S and P. 
Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P. 
Return "-1" in case there is no such window present. 
In case there are multiple such windows of same length, return the one with the least starting index.
Note : All characters are in Lowercase alphabets. 
*/

 string smallestWindow (string s, string p)
    {
        // Your code here
        int len1=s.length();
        int len2=p.length();
        
        if(len1<len2) return "-1";
        
        int freq_str[256]={0};
        int freq_pat[256]={0};
        
        for(int i=0; i<len2 ; ++i) freq_pat[p[i]]++;
        
        int start=0,start_index=-1,min_len=INT_MAX,count=0;
        
        for(int j=0; j<len1; ++j) {
            
            freq_str[s[j]]++;
            
            if(freq_str[s[j]]<=freq_pat[s[j]])
                ++count;
                
            if(count==len2) {
                
                while(freq_str[s[start]] > freq_pat[s[start]] || freq_pat[s[start]]==0) {
                    
                  //  if(freq_str[s[start]] > freq_pat[s[start]])
                        freq_str[s[start]]--;
                        
                    start++;
                }
                
                int len_window = j - start + 1;
                if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
            
        }
        
        
    }
    
    if(start_index==-1) 
        return "-1";
        
    else 
        return s.substr(start_index, min_len);
    
    }
    int main() {
        string str="i.like.this.program.very.much";
        cout<<reverseWords(str);

        return 0;
    }