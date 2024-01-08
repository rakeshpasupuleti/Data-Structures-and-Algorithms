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

/*
Strongly Connected Components (Kosaraju's Algo)
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges.
Find the number of strongly connected components in the graph.


*/
// private:
    void do_dfs(int node, const std::vector<std::vector<int>>& adj, std::vector<int>& visited, std::stack<int>& st) {
        visited[node] = true;

        for (auto child : adj[node]) {
            if (!visited[child])
                do_dfs(child, adj, visited, st);
        }

        st.push(node);
    }

// public:
    // Function to find the number of strongly connected components in the graph.
    int kosaraju(int V, const std::vector<std::vector<int>>& adj) {
        std::vector<int> visited(V, false);
        std::stack<int> st;
        std::stack<int> st2;
        std::vector<std::vector<int>> adjtr(V);
        int scc_count = 0;

        // Step 1: Perform DFS and fill the stack with finishing times.
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                do_dfs(i, adj, visited, st);
            }
        }

        // Step 2: Transpose the graph.
        for (int i = 0; i < V; ++i) {
            visited[i] = false;

            for (auto node : adj[i]) {
                adjtr[node].push_back(i);
            }
        }

        // Step 3: Perform DFS on the transposed graph using the finishing times.
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                scc_count++;
                do_dfs(node, adjtr, visited, st2);
            }
        }

        return scc_count;
    }


/*
Shortest Source to Destination Path

Given a 2D binary matrix A(0-based index) of dimensions NxM. 
Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.
*/

// Helper function to check if a given position (row, col) is valid within the grid.
    bool isvalid(int row, int col, int N, int M) {
        // Returns true if the position is within the grid boundaries, otherwise false.
        return (row >= 0 && row < N && col >= 0 && col < M);
    }


    // Function to find the shortest distance from the top-left corner (0, 0) to a given destination (X, Y)
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // Create a matrix to keep track of visited positions in the grid.
        vector<vector<int>> visited(N, vector<int>(M, 0));

        // Initialize a queue for BFS traversal and enqueue the starting position (0, 0).
        queue<pair<int, int>> qu;
        if (A[0][0] == 0)
            return -1; // If the starting position is blocked, return -1.

        qu.push({0, 0});
        visited[0][0] = 1; // Mark the starting position as visited.

        // Arrays to represent possible movements: up, down, left, right.
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        int min_dist = -1; // Initialize the minimum distance to -1.

        // Perform BFS traversal to find the shortest distance.
        while (!qu.empty()) {
            int size = qu.size();
            min_dist++; // Increment the minimum distance for each level of BFS.

            // Explore all positions at the current level.
            for (int i = 0; i < size; ++i) {
                int r = qu.front().first;
                int c = qu.front().second;
                qu.pop();

                // If the current position is the destination, return the minimum distance.
                if (r == X && c == Y)
                    return min_dist;

                // Explore all possible moves from the current position.
                for (int i = 0; i < 4; ++i) {
                    int row = dx[i] + r;
                    int col = dy[i] + c;

                    // Check if the new position is valid, unvisited, and accessible (A[row][col] == 1).
                    if (isvalid(row, col, N, M) && !visited[row][col] && A[row][col] == 1) {
                        qu.push({row, col}); // Enqueue the new position for further exploration.
                        visited[row][col] = 1; // Mark the new position as visited.
                    }
                }
            }
        }

        return -1; // If the destination is not reachable, return -1.
    }

/*

Find whether path exist

Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.
*/

// Function to check if given indices (r, c) are valid in the grid of size (n, m).
    bool isvalid(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }


    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        // Initialize variables
        int r, c;
        int n = grid.size();
        int m = grid[0].size();
        
        // Create a 2D array to keep track of visited cells
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        // Find the starting cell with value 1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    r = i;
                    c = j;
                    break;
                }
            }
        }

        // Use BFS to traverse the grid and find a path
        queue<pair<int, int>> q;
        // stack<pair<int, int>> q; //If DFs is used
        q.push({r, c});
        
        // Arrays to represent possible moves (up, down, left, right)
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            // Retrieve current cell from the queue
            int x = q.front().first;
            int y = q.front().second;
            
            // int x = q.top().first;
            // int y = q.top().second;
            
            q.pop();
            
            // If the destination is found, return true
            if (grid[x][y] == 2)
                return true;

            // Mark the current cell as visited
            visited[x][y] = 1;

            // Explore possible moves from the current cell
            for (int i = 0; i < 4; ++i) {
                int row = dx[i] + x;
                int col = dy[i] + y;

                // Check if the new cell is valid, not visited, and not an obstacle (value 0)
                if (isvalid(row, col, n, m) && !visited[row][col] && grid[row][col] != 0) {
                    q.push({row, col});
                }
            }
        }
        
        // If the destination is not reached, return false
        return false;
    }

/*
Minimum Cost Path
Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 

Note: It is assumed that negative cost cycles do not exist in the input matrix.
*/

//Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
    // Get the number of rows and columns in the grid
    int n = grid.size();
    int m = grid[0].size();

    // Create a 2D array to store minimum costs for each cell
    vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));

    // Min heap to keep track of cells with the minimum cost
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Start from the top-left cell
    pq.push({grid[0][0], {0, 0}});
    minCost[0][0] = grid[0][0];

    // Possible moves (left, right, up, down)
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    // Iterate until the priority queue is empty
    while (!pq.empty()) {
        // Extract the cell with the minimum cost
        int cost = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        // Explore neighbors of the current cell
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            // Check if the new cell is within bounds and has a lower cost
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                minCost[newRow][newCol] > cost + grid[newRow][newCol]) {
                
                // Update the minimum cost for the new cell
                minCost[newRow][newCol] = cost + grid[newRow][newCol];

                // Add the new cell to the priority queue
                pq.push({minCost[newRow][newCol], {newRow, newCol}});
            }
        }
    }

    // Return the minimum cost to reach the bottom-right cell
    return minCost[n - 1][m - 1];
}

/*
Circle of strings
Given an array of lowercase strings A[] of size N, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is same as first character of Y. 
If every string of the array can be chained with exactly two strings of the array(one with the first character and second with the last character of the string), it will form a circle.

For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"
*/
// Depth-First Search (DFS) function to traverse the graph starting from a given node
void do_dfs(vector<int> adj[], vector<bool> &visited, int node) {
    // Mark the current node as visited
    visited[node] = true;

    // Explore all neighbors (children) of the current node
    for (auto child : adj[node]) {
        // If the neighbor has not been visited, recursively call DFS on it
        if (!visited[child]) {
            do_dfs(adj, visited, child);
        }
    }
}

// Function to check if the graph is connected starting from a specific node
bool isconnected(vector<int> adj[], vector<bool> &vertices, int node) {
    // Initialize a boolean array to track visited nodes during DFS
    vector<bool> visited(26, false);

    // Perform DFS starting from the given node
    do_dfs(adj, visited, node);

    // Check if all vertices marked in 'vertices' are visited
    for (int i = 0; i < 26; ++i) {
        if (vertices[i] && !visited[i])
            return false; // If any required vertex is not visited, the graph is not connected
    }

    return true; // The graph is connected
}

// Class function to determine if the given set of strings forms a valid circle
int isCircle(int N, vector<string> A) {
    // Create an adjacency list to represent the graph
    vector<int> adj[26];

    // Boolean array to represent the presence of vertices in the graph
    vector<bool> vertices(26, false);

    // Arrays to store in-degrees and out-degrees of vertices
    vector<int> in_degree(26, 0), out_degree(26, 0);

    // Populate the graph and calculate in-degrees and out-degrees
    for (int i = 0; i < N; ++i) {
        int f = A[i][0] - 'a';
        int l = A[i][A[i].size() - 1] - 'a';

        vertices[f] = true;
        vertices[l] = true;

        in_degree[l]++;
        out_degree[f]++;

        adj[f].push_back(l);
    }

    // Check if in-degrees and out-degrees are equal for each vertex
    for (int i = 0; i < 26; i++) {
        if (in_degree[i] != out_degree[i])
            return 0; // If not equal, the graph does not form a valid circle
    }

    // Check if the graph is connected starting from the first character of the first string
    return isconnected(adj, vertices, A[0][0] - 'a');
}


/*
Floyd Warshall
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. 
Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
Do it in-place.
*/

void shortest_distance(vector<vector<int>>& matrix) {
    // Initialize the size of the matrix
    int n = matrix.size();
    
    // Convert -1 values in the matrix to INT_MAX for proper comparison
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == -1)
                matrix[i][j] = INT_MAX;
        }
    }
    
    // Apply the Floyd-Warshall algorithm to find the shortest distances
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Update the shortest distance if a shorter path is found
                if (matrix[i][j] > matrix[i][k] + matrix[k][j] && matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX)
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    
    // Convert INT_MAX values back to -1 for representing unreachable nodes
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == INT_MAX)
                matrix[i][j] = -1;
        }
    }
}

/*
Alien Dictionary
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
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
    
    string findOrder(string dict[], int N, int K) {
        // Vector to represent the adjacency list
        vector<int> adj[K];

        // Vector to store the topological sorting result
        vector<int> toposort;

        // String to store the final result
        string result = "";

        // Iterate through the given words to build the adjacency list
        for (int i = 0; i < N - 1; ++i) {
            string word1 = dict[i];
            string word2 = dict[i + 1];

            // Find the first character difference between two consecutive words
            int len = min(word1.size(), word2.size());
            int idx = 0;
            while (idx < len) {
                if (word1[idx] != word2[idx]) {
                    // Add an edge to the adjacency list
                    adj[word1[idx] - 'a'].push_back(word2[idx] - 'a');
                    break;
                }
                ++idx;
            }
        }

        // Perform topological sorting
        toposort = topoSort(K, adj);

        // Convert the result to a string using characters
        for (int x : toposort)
            result = result + char(x + 'a');

        // Return the final result
        return result;
        
 }


/*

Snake and Ladder Problem
Given a 5x6 snakes and ladders board, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from the source (1st cell).

You are given an integer N denoting the total number of snakes and ladders and an array arr[] of 2*N size where 2*i and (2*i + 1)th values denote the starting and ending point respectively of ith snake or ladder. The board looks like the following.
Note: Assume that you have complete control over the 6 sided dice. No ladder starts from 1st cell.
*/
int minThrow(int N, int arr[]) {
    // Create an array to represent the edges of the snakes and ladders board.
    // Initialize all elements to -1, indicating no snake or ladder at that position.
    vector<int> edges(30, -1);

    // Create an array to keep track of visited cells.
    vector<bool> visited(30, false);

    // Populate the edges array based on the given snake and ladder positions.
    for (int i = 0; i < N; ++i)
        edges[arr[2 * i] - 1] = arr[2 * i + 1] - 1;

    // Create a queue to perform BFS traversal.
    queue<pair<int, int>> q;

    // Start from the first cell (0-based index) and mark it as visited.
    q.push({0, 0});
    visited[0] = true;

    // Perform BFS traversal to find the minimum number of dice throws.
    while (!q.empty()) {
        // Retrieve the current node and its distance from the source.
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        // Mark the current node as visited.
        visited[node] = true;

        // Iterate over possible children (next cells) of the current node.
        for (int child = node + 1; child <= (node + 6) && child < 30; ++child) {
            // If the destination cell (29) is reached, return the distance.
            if (child == 29)
                return dist + 1;

            // If the child is not visited, enqueue it for further exploration.
            if (!visited[child]) {
                // If there is no snake or ladder at the child position, move directly.
                if (edges[child] == -1)
                    q.push({child, dist + 1});
                // If there is a snake or ladder, move to the destination of the snake/ladder.
                else
                    q.push({edges[child], dist + 1});
            }
        }
    }

    // If the destination cell cannot be reached, return -1.
    return -1;
}


int main() {

    return 0;
     int V = 5 ;
     vector<int> adj[]= {{2,3,1}, {0}, {0,4}, {0}, {2}};
     vector<int> result=dfsOfGraph(V, adj);
}