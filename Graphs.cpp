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

/*
Topological sort
Given a Directed Acyclic Graph (DAG) with V vertices and E edges.
Find any Topological Sorting of that Graph.
*/



vector<int> topoSort(int V, vector<int> adj[]) 
{
    // Initialize the result vector to store the topological ordering
    vector<int> result;

    // Vector to store the in-degrees of each vertex
    vector<int> inedges(V, 0);

    // Queue to store nodes with in-degree 0
    queue<int> zeronode;

    // Counter to keep track of the number of visited nodes
    int Visited_nodes = 0;

    // Calculate in-degrees for each node
    for (int i = 0; i < V; ++i)
        for (auto node : adj[i]) {
            inedges[node]++;
        }

    // Push nodes with in-degree 0 into the queue
    for (int i = 0; i < V; ++i)
        if (inedges[i] == 0)
            zeronode.push(i);

    // Perform topological sorting using Kahn's algorithm
    while (!zeronode.empty()) {
        // Extract a node with in-degree 0 from the queue
        auto temp = zeronode.front();
        zeronode.pop();

        // Add the node to the result vector
        result.push_back(temp);

        // Update in-degrees of adjacent nodes
        for (auto node : adj[temp]) {
            inedges[node]--;

            // If in-degree becomes 0, push the node into the queue
            if (inedges[node] == 0)
                zeronode.push(node);

            // Increment the counter for visited nodes
            Visited_nodes++;
        }
    }

    // Return the topologically sorted result
    return result;
}

/*

Find the number of islands

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
*/

// Function to check if given row and column indices are within the valid dimensions of the grid
bool isvalid_dimensions(vector<vector<char>>& grid, int row, int col) {
    // Get the number of rows in the grid
    int n = grid.size();
    // Get the number of columns in the grid (assuming non-empty grid)
    int m = grid[0].size();
    
    // Check if the indices are within bounds
    return (row >= 0 && row < n && col >= 0 && col < m);
}

// Depth-First Search (DFS) function to explore and mark connected '1's in the grid
void find_dfs(vector<vector<char>>& grid, int i, int j) {
    // Offsets for the eight possible directions (up, down, left, right, and diagonals)
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    // Iterate over all eight directions
    for(int dir = 0; dir < 8; dir++) {
        // Calculate new row and column indices based on the current direction
        int row = i + dx[dir];
        int col = j + dy[dir];
        
        // Check if the new indices are within valid dimensions and the cell contains '1'
        if (isvalid_dimensions(grid, row, col) && grid[row][col] == '1') {
            // Mark the current cell as visited (change '1' to '0')
            grid[row][col] = '0';
            // Recursively explore the connected region
            find_dfs(grid, row, col);
        }
    }
}

// Function to count the number of islands in the given 2D grid
int numIslands(vector<vector<char>>& grid) {
    // Initialize the count of islands
    int islands_count = 0;
    // Get the number of rows in the grid
    int n = grid.size();
    // Get the number of columns in the grid (assuming non-empty grid)
    int m = grid[0].size();
    
    // Iterate over all cells in the grid
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            // If the current cell contains '1', increment the island count and explore the island
            if (grid[i][j] == '1') {
                islands_count++;
                // Mark the current cell as visited (change '1' to '0')
                grid[i][j] = '0';
                // Explore the connected region using DFS
                find_dfs(grid, i, j);
            }
        }
    }
    
    // Return the total count of islands
    return islands_count;
}

/*

Implementing Dijkstra Algorithm

Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. 
You have to return a list of integers denoting shortest distance between each node and Source vertex S.

Note: The Graph doesn't contain any negative weight cycle.
*/


vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Initialize a vector to store minimum distances from source to all nodes
    vector<int> mindist(V, INT_MAX);
    
    // Set the distance from the source to itself as 0
    mindist[S] = 0;

    // Priority queue to store pairs of distance and node with min distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Push the source node with distance 0 to the priority queue
    pq.push({0, S});

    // Dijkstra's algorithm
    while (!pq.empty()) {
        // Extract the node with the minimum distance from the priority queue
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Iterate through the adjacent nodes of the current node
        for (auto it : adj[node]) {
            int edgeWeight = it[1];  // Weight of the edge
            int adjNode = it[0];     // Adjacent node

            // Relaxation step: Update the distance if a shorter path is found
            if (dist + edgeWeight < mindist[adjNode]) {
                mindist[adjNode] = dist + edgeWeight;

                // Push the updated distance and node to the priority queue
                pq.push({mindist[adjNode], adjNode});
            }
        }
    }

    // Return the vector containing the minimum distances from the source
    return mindist;
}

/*
Minimum Swaps to Sort
Given an array of n distinct elements. 
Find the minimum number of swaps required to sort the array in strictly increasing order.

*/

int minSwaps(vector<int>& originalArray) {
    int swapCount = 0;

    unordered_map<int, int> elementIndexMap;

    int arraySize = originalArray.size();

    vector<int> sortedArray(arraySize);

    // Build a map to store the index of each element in the original array
    for (int i = 0; i < arraySize; ++i) {
        elementIndexMap[originalArray[i]] = i;
        sortedArray[i] = originalArray[i];
    }

    // Sort the copy of the original array
    sort(sortedArray.begin(), sortedArray.end());

    // Perform swaps to bring elements to their correct positions
    for (int i = 0; i < arraySize; ++i) {
        if (sortedArray[i] != originalArray[i]) {
            int destinationIndex = elementIndexMap[sortedArray[i]];
            int currentValue = originalArray[i];

            // Swap elements to bring them to their correct positions
            swap(originalArray[i], originalArray[destinationIndex]);

            // Update the index map after the swap
            elementIndexMap[sortedArray[i]] = i;
            elementIndexMap[currentValue] = destinationIndex;

            swapCount++;
        }
    }

    return swapCount;
}


int main() {

    return 0;
     int V = 5 ;
     vector<int> adj[]= {{2,3,1}, {0}, {0,4}, {0}, {2}};
     vector<int> result=dfsOfGraph(V, adj);
}