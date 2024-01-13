 
 #include<bits/stdc++.h>
using namespace std;


 vector <int> search(string pat, string txt)
        {
            //code here
            
            int n = txt.length();
            int m = pat.length();
            vector<int> result;
            vector<int> lps(m, 0);

            int prevlps = 0, i = 1, j=0;
            while( i < m ) {

                if(pat[i]==pat[prevlps]) {

                    lps[i] = prevlps + 1;
                    ++prevlps;
                    ++i;
                }
                else if(prevlps == 0) {
                        lps[i] == 0;
                        ++i;
                    }
                    else {
                         
                         prevlps = lps[prevlps -1 ];
                    }
                }

                i = 0, j = 0;
                while( i < n) {

                    if( txt[i] == pat[j]) 
                        ++i, ++j;
                    else {

                        if(j==0) {
                            ++i;
                        }
                        else {

                            j = lps[j-1];
                        }
                    }

                    if(j==m) {
                             result.push_back(i-m + 1);
                             j = lps[j-1];
                    }
                       

                }


                return result;
            
            }
            
            
   

    int main() {
    

    vector<int> result = search("geek" , "geeksforgeeks" );
 
    for(auto x: result) 
       cout<<x<<"  ";

    return 0;
}
