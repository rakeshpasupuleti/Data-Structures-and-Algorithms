#include<iostream>
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <numeric>
#include<stack>
#include<queue>
using namespace std;

 /*
DFS of Graph
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.   
 */


void DFS(int node, vector<int> adj[], vector<int> &visited, vector<int> &result) {
    // Mark the current node as visited
    visited[node] = 1;

    // Add the current node to the result vector
    result.push_back(node);

    // Explore all adjacent nodes
    for (auto child : adj[node]) {
        // If the child node is not visited, recursively call DFS for that node
        if (visited[child] != 1)
            DFS(child, adj, visited, result);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Initialize the result vector to store the DFS traversal
    vector<int> result;

    // Initialize the visited array to track visited nodes, initially set to 0 (not visited)
    vector<int> visited(V, 0);

    // Start DFS traversal from the first node (0-indexed)
    DFS(0, adj, visited, result);

    // Return the DFS traversal result
    return result;
}

/*
using the iterative method
*/

  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Initialize a stack for DFS traversal
    stack<int> st;

    // vector to track visited nodes, initially set to 0 (not visited)
   vector<int> visited(V,0);

    // Vector to store the DFS traversal result
    vector<int> result;

   
    // Start DFS from the first node (0-indexed)
    st.push(0);

    // Main DFS loop
    while (!st.empty()) {
        // Get the top element of the stack
        int idx = st.top();
        int i = adj[idx].size() - 1;
        st.pop();

        // If the current node is not visited, add it to the result vector
        if (visited[idx] == 0)
            result.push_back(idx);

        // Mark the current node as visited
        visited[idx] = 1;

        // Explore adjacent nodes
        while (i >= 0) {
            // If the adjacent node is not visited, push it onto the stack
            if (visited[adj[idx][i]] != 1)
                st.push(adj[idx][i]);

            // Move to the next adjacent node
            --i;
        }
    }

    // Return the DFS traversal result
    return result;
}


/*
BFS of graph
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. 
Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

*/

 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Create a queue to perform breadth-first search
    queue<int> q;
    
    // Vector to store the result of the breadth-first search
    vector<int> result;
    
    // Vector to keep track of visited nodes, initialized to 0 (not visited)
    vector<int> visited(V, 0);
    
    // Start the breadth-first search from the first node (node 0)
    q.push(0);
    
    // Continue the breadth-first search until the queue is not empty
    while (!q.empty()) {
        // Get the front node from the queue
        int node = q.front();
        q.pop();
        
        // If the node is not visited, add it to the result
        if (visited[node] == 0)
            result.push_back(node);
        
        // Mark the current node as visited
        visited[node] = 1;
        
        // Explore all the adjacent nodes (children) of the current node
        for (auto child : adj[node]) {
            // If the child is not already visited, add it to the queue
            if (visited[child] != 1)
                q.push(child);
        }
    }
    
    // Return the result of the breadth-first search
    return result;
}

/*
Detect cycle in an undirected graph
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.
*/

bool find_cycle(vector<int> adj[], int node, int parent, vector<int> &visited) {
    // Mark the current node as visited
    visited[node] = 1;

    // Traverse all adjacent nodes (children) of the current node
    for (auto child : adj[node]) {
        // If the child is not visited, perform DFS on the child
        if (!visited[child]) {
            // Recursively call the function on the child, with the current node as its parent
            if (find_cycle(adj, child, node, visited)) 
                return true;
        }
        // If the child is visited and not the parent, a cycle is detected
        else if (child != parent)
            return true;
    }

    // No cycle is found in the current DFS traversal
    return false;
}

// Function to check if the graph contains a cycle
bool isCycle(int V, vector<int> adj[]) {
    // Initialize a vector to keep track of visited nodes
    vector<int> visited(V, 0);

    // Iterate over all nodes in the graph
    for (int i = 0; i < V; ++i) {
        // If the current node is not visited, perform DFS to check for cycles
        if (!visited[i]) {
            if (find_cycle(adj, i, -1, visited)) 
                return true; // If a cycle is detected, return true
        }
    }

    // No cycle is found in the entire graph
    return false;
}






/*
Detect cycle in a directed graph
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
*/


//Using DFS

// Function to check if there is a cycle in a directed graph using DFS
// Parameters:
//   - adj[]: An array of vectors representing the adjacency list of the graph
//   - node: Current node being processed
//   - visited: A vector to keep track of visited nodes
//   - path_visited: A vector to keep track of nodes visited in the current DFS path
bool find_cycle_in_directed(vector<int> adj[], int node, vector<int> &visited, vector<int> &path_visited) {
        
    // Mark the current node as visited and part of the current path
    visited[node] = 1;
    path_visited[node] = 1;

    // Traverse all adjacent nodes
    for (auto child : adj[node]) {

        // If the child is not visited, recursively check for a cycle
        if (!visited[child] && find_cycle_in_directed(adj, child, visited, path_visited))
            return true;

        // If the child is already part of the current path, a cycle is found
        else if (path_visited[child] == 1)
            return true;
    }

    // Mark the current node as not part of the current path
    path_visited[node] = 0;
    return false;
}

// Function to check if the directed graph represented by an adjacency list contains a cycle
// Parameters:
//   - V: Number of vertices in the graph
//   - adj[]: An array of vectors representing the adjacency list of the graph
bool isCyclic(int V, vector<int> adj[]) {
    
    // Initialize vectors to keep track of visited nodes and nodes visited in the current DFS path
    vector<int> visited(V, 0);
    vector<int> path_visited(V, 0);

    // Traverse all nodes in the graph
    for (int i = 0; i < V; ++i) {

        // If the current node is not visited, check for a cycle starting from this node
        if (!visited[i])
            if (find_cycle_in_directed(adj, i, visited, path_visited))
                return true;
    }

    // No cycle found in the graph
    return false;
}





int main() {

    return 0;
     int V = 5 ;
     vector<int> adj[]= {{2,3,1}, {0}, {0,4}, {0}, {2}};
     vector<int> result=dfsOfGraph(V, adj);
}