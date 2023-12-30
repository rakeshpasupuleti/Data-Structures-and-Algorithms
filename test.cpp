 
 
 #include<iostream>
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <numeric>
#include<stack>
#include<queue>
using namespace std;


 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        vector<int> result(V, INT_MAX);
        result[S]=0;
        
        for (auto x : adj[S])
             result[x[0]] = x[1];

        
        
       
        for( int idx=0; idx<V; ++idx) {
            
            for( auto temp: adj[idx]) {
                
                int des = temp[0];
                int wt = temp[1];
                if( result[des] > result[idx]+wt) {
                    
                    result[des] = result[idx]+wt;
                }
            }
        }
        
        
        return result;
    }

   int main() {
    vector<vector<pair<int, int>>> adj[] = {
        {{1, 9}, {3, 4}, {5, 4}},
        {{4, 4}},
        {{5, 10}},
        {},
        {{5, 3}},
        {}
    };

    int S = 0; // Source vertex is 0 (adjust as needed)
    int V = 6;

    vector<int> res = dijkstra(V, adj, S);

    cout << "The result are " << endl;
    for (auto x : res)
        cout << x << " ";

    return 0;
}
