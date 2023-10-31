#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <numeric>
#include <stack>
#include<queue>

/*
The Three Laws of Recursion
1. A recursive algorithm must have a base case.
2. A recursive algorithm must change its state and move toward the base case.
3. A recursive algorithm must call itself, recursively.

A base case is the condition that allows the algorithm to stop recursing.

A base case is typically a problem that is small enough to solve directly.
In the factorial algorithm the base case is n=1.
We must arrange for a change of state that moves the algorithm toward the base case.

A change of state means that some data that the algorithm is using is modified.
Usually the data that represents our problem gets smaller in some way.
In the factorial n decreases.
*/

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

/*
Height of Binary Tree
Given a binary tree, find its height.
*/

int height(struct Node* node){
        // code here 
    /*
    //Recursive method
    
      // If the current node is NULL (i.e., it's a leaf or an empty subtree), its height is 0.
    if (node == NULL) {
        return 0;
    }

    // Recursively calculate the height of the left and right subtrees.
    int left_height = height(node->left);
    int right_height = height(node->right);
    
    // Calculate the height of the current node as the maximum of left and right subtree heights,
    // plus 1 (for the current level).
    int curr_height = (left_height > right_height) ? (left_height + 1) : (right_height + 1);

    // Return the height of the current node (subtree) to the caller.
    return curr_height;
       
      */
        
        // Initialize a queue to perform level-order traversal
    queue<Node *> q;
    
    // Start by pushing the root node into the queue
    q.push(node);
    
    // Initialize the height to 0, which will be incremented as we traverse the tree
    int height = 0;

    // Perform level-order traversal using a while loop
    while (!q.empty()) {
        // Get the number of nodes at the current level
        int size = q.size();
        
        // Process all nodes at the current level
        for (int i = 0; i < size; ++i) {
            // Remove a node from the queue
            Node *temp = q.front();
            q.pop();
            
            // If the node has a left child, add it to the queue
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            
            // If the node has a right child, add it to the queue
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
        
        // Increment the height for each level
        ++height;
    }
    
    // Return the computed height of the binary tree
    return height;
    }

/*
Count Leaves in Binary Tree
Given a Binary Tree of size N, You have to count leaves in it. 
For example, there are two leaves in following tree
*/
int countLeaves(Node* root)
{
  // Your code here
/*

//Recursive Method
 if(root==NULL) return 0;
       else if(root->left==NULL && root->right==NULL)   return 1;
       
       int left_leaves_count=countLeaves(root->left);
       int right_leaves_count=countLeaves(root->right);
       
       int curr_leaves_count= left_leaves_count + right_leaves_count;
       
       return curr_leaves_count;
*/

    queue<Node*> q;
    q.push(root);
    int count = 0;
    
    // Perform level-order traversal using a while loop
    while (!q.empty()) {
        
        Node* temp = q.front();
        q.pop();
        
        // Check if the current node is a leaf (both left and right children are NULL)
        if (temp->left == NULL && temp->right == NULL) {
            // If it's a leaf, increment the count
            ++count;
        }
        
        // If the node has a left child, add it to the queue for future processing
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        
        // If the node has a right child, add it to the queue for future processing
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
    
    // Return the count of leaf nodes in the binary tree
    return count;

  
}

/*
Check for Balanced Tree
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 
*/
// Function to calculate the height of a binary tree and check if it's balanced
int height(Node* node) {
    // If the current node is NULL, its height is 0.
    if (node == NULL) {
        return 0;
    }

    // Recursively calculate the height of the left subtree.
    int left_height = height(node->left);
    
    // If the left subtree is unbalanced (-1), propagate the unbalanced value up the tree.
    if (left_height == -1) {
        return -1;
    }

    // Recursively calculate the height of the right subtree.
    int right_height = height(node->right);
    
    // If the right subtree is unbalanced (-1), propagate the unbalanced value up the tree.
    if (right_height == -1) {
        return -1;
    }

    // Check if the absolute difference between left and right subtree heights is more than 1.
    if (abs(left_height - right_height) > 1) {
        return -1; // The tree is unbalanced at this node.
    } else {
        // Return the maximum height of left and right subtrees plus 1 for the current node.
        return max(left_height, right_height) + 1;
    }
}

// Function to check if a binary tree is balanced
bool isBalanced(Node* root) {
    // The tree is balanced if the height function does not return -1 (unbalanced).
    return (height(root) != -1);
}

/*
Determine if Two Trees are Identical
Given two binary trees, the task is to find if both of them are identical or not. 
*/

bool validation( Node* r1, Node *r2) {
        if(r1==NULL || r2==NULL)
            return false;
        if(r1->data != r2->data )
            return false;
            
        return true;
    }

bool isIdentical(Node *r1, Node *r2) {
    
    /*
    // Recursive Method
    // This is a recursive approach for checking the identical of two trees.
    // It compares the current nodes in both trees and their subtrees recursively.
    // If the nodes are both NULL, it returns true.
    // If one of the nodes is NULL or their data doesn't match, it returns false.
    // It then checks the left and right subtrees for similarity.
    
    if (r1 == NULL && r2 == NULL)
        return true;
    if (r1 == NULL || r2 == NULL)
        return false;
    if (r1->data != r2->data)
        return false;
    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    */
    
    // Iterative Method Using Queues
    // This is an iterative approach for checking the identical of two trees.
    // It uses two queues to perform a level-order traversal of both trees.
    // At each level, it compares the data in corresponding nodes.
    // If the data doesn't match or one node is NULL while the other isn't,
    // it returns false. Otherwise, it enqueues the left and right children
    // for further comparison.
    
    if (r1 == NULL && r2 == NULL)    
        return true;
    if (!validation(r1, r2))
        return false;
        
    queue<Node *> q1;
    queue<Node *> q2;
    
    q1.push(r1);
    q2.push(r2);
    
    while (!q1.empty() && !q2.empty()) {
        Node *temp1 = q1.front();
        q1.pop();
        Node *temp2 = q2.front();
        q2.pop();
        
        // Check for the left child
        if (!(temp1->left == NULL && temp2->left == NULL)) {
            if (validation(temp1->left, temp2->left)) {
                q1.push(temp1->left);
                q2.push(temp2->left);
            } else
                return false;
        } 
        
        // Check for the right child
        if (!(temp1->right == NULL && temp2->right == NULL)) {
            if (validation(temp1->right, temp2->right)) {
                q1.push(temp1->right);
                q2.push(temp2->right);
            } else 
                return false;
        }  
    }
    
    // If both queues are empty, it means both trees are identical.
    return q1.empty() && q2.empty();
}

/*
Symmetric Tree
Given a Binary Tree. Check whether it is Symmetric or not, i.e. 
whether the binary tree is a Mirror image of itself or not.
*/


/*
bool isIdentical(Node *r1, Node *r2) {
    
   
    
    if (r1 == NULL && r2 == NULL)
        return true;
    if (r1 == NULL || r2 == NULL)
        return false;
    if (r1->data != r2->data)
        return false;
    return isIdentical(r1->left, r2->right) && isIdentical(r1->right, r2->left);
    
}
*/

    bool validation(Node *temp1, Node * temp2) {
        
        if(temp1==NULL && temp2==NULL)
            return true;
        else return(temp1 && temp2 && temp1->data==temp2->data);
            
    }
    
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    /*
	    //Recursive approch
	    if(root==NULL )
	        return true;
	    else
	        return (isIdentical(root->left, root->right));
	   */
	  //Iterative approch
	  queue<Node *>q;
	  
	  if(root==NULL)
	    return true;
	    
	  q.push(root);
	  q.push(root);
	  
	  while(!q.empty()) {
	      
	      Node * temp1=q.front();
	      q.pop();
	      
	      Node * temp2=q.front();
	      q.pop();
	      
	      if(temp1==NULL && temp2==NULL)
	        continue;
	        
	      if(validation(temp1, temp2)) {
	          
	          if(validation(temp1->left, temp2->right)) {
	              q.push(temp1->left);
	              q.push(temp2->right);
	          }
	          else 
	            return false;
	          if(validation(temp1->right, temp2->left)) {
	              q.push(temp1->right);
	              q.push(temp2->left);
	          }
	          else
	            return false;
	          
	          
	      }
	      else
	        return false;
	   
	  }
	  
	  return true;
	    
	   
    }

/*
Left View of Binary Tree
Given a Binary Tree, return Left view of it. 
Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 
The task is to complete the function leftView(), which accepts root of the tree as argument.
*/

void find_left_view(Node *root, int curr_level, int &max_level, vector<int> &result) {
    if (curr_level > max_level) {
        // If the current level is greater than the maximum level seen so far,
        // add the node's data to the result and update the max_level.
        result.push_back(root->data);
        max_level = curr_level;
    }

    // Recursively explore the left subtree.
    if (root->left != NULL)
        find_left_view(root->left, curr_level + 1, max_level, result);

    // Recursively explore the right subtree.
    if (root->right != NULL)
        find_left_view(root->right, curr_level + 1, max_level, result);
}

// Main function to find the left view of the binary tree.
vector<int> leftView(Node *root) {
    vector<int> result;
    int curr_level = 1; // Start at level 1 (root node).
    int max_level = 0; // Initialize max_level to 0.

    if (root == NULL)
        return result; // If the tree is empty, return an empty result.

    // Call the recursive function to find the left view.
    find_left_view(root, curr_level, max_level, result);

    // Return the result, which contains the left view of the binary tree.
    return result;
    
    /*
  //Iterative Approch
  vector<int> result;
  queue<Node *> q;
   
  if(root==NULL)
    return result;
    
    q.push(root);
    
    while(!q.empty()) {
        
        int len=q.size();
        
        result.push_back(q.front()->data);
        
        for(int i=0; i<len; ++i) {
            
            Node * temp=q.front();
            q.pop();
            
            
            if(temp->left !=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
   
   
  return result;
  
  */
}

/*
Bottom View of Binary Tree
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.
*/

void find_bottomView(Node *root, int curr_level, int h_dist, int &min_h_dist, int &max_h_dist, unordered_map<int, pair<int, int>> &umap) {
    // Check if the horizontal distance (h_dist) is already present in the unordered map.
    if (umap.find(h_dist) != umap.end()) {
        // If it is, update the entry if the current level is greater than or equal to the stored level.
        if (curr_level >= umap[h_dist].first)
            umap[h_dist] = {curr_level, root->data};
    } else {
        // If the horizontal distance is not in the map, add it with the current level and node's data.
        umap[h_dist] = {curr_level, root->data};
    }

    // Update the minimum and maximum horizontal distances.
    min_h_dist = min(h_dist, min_h_dist);
    max_h_dist = max(h_dist, max_h_dist);

    // Recursively traverse the left and right subtrees.
    if (root->left != NULL)
        find_bottomView(root->left, curr_level + 1, h_dist - 1, min_h_dist, max_h_dist, umap);
    if (root->right != NULL)
        find_bottomView(root->right, curr_level + 1, h_dist + 1, min_h_dist, max_h_dist, umap);
}

// This function finds the bottom view of a binary tree.
vector<int> bottomView(Node *root) {
    // Initialize the result vector and an unordered map to store (horizontal distance, (level, value)) pairs.
    vector<int> result;
    unordered_map<int, pair<int, int>> umap;

    // Initialize variables to keep track of the current level, horizontal distance, minimum and maximum horizontal distances.
    int curr_level = 1;
    int h_dist = 0;
    int min_h_dist = INT_MAX;
    int max_h_dist = INT_MIN;

    // Check if the tree is empty, and return an empty result if it is.
    if (root == NULL)
        return result;

    // Call the recursive function to find the bottom view of the binary tree.
    find_bottomView(root, curr_level, h_dist, min_h_dist, max_h_dist, umap);

    // Iterate through the horizontal distances and add the values to the result vector.
    for (int i = min_h_dist; i <= max_h_dist; ++i) {
        result.push_back(umap[i].second);
    }

    // Return the result, which contains the bottom view of the binary tree.
    return result;
    
    /*
    //Iterative method
    
    unordered_map<int,int> umap;
     queue<pair<Node*, int>>q;
     vector<int> result;
     int minhd=0,maxhd=0;
     if(root==NULL) return result;
     q.push({root,0});
     
     while(!q.empty()){
         Node *temp=q.front().first;
         int hdist=q.front().second;
         q.pop();
         umap[hdist]=temp->data;
         if(temp->left) {
             q.push({temp->left,hdist-1});
             minhd=min(minhd,hdist-1);
         }
         if(temp->right) {
             q.push({temp->right,hdist+1});
             maxhd=max(maxhd,hdist+1);
         }
         
         
     }
     
     for(int i=minhd;i<=maxhd;++i) result.push_back(umap[i]);
     return result;
    }
    */
}

/*
Vertical Traversal of Binary Tree
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.
*/
vector<int> verticalOrder(Node *root)
{
    // Create an unordered map to store nodes at each horizontal distance.
    unordered_map<int, vector<int>> umap;
    // Initialize the result vector to store the vertical order.
    vector<int> result;
    // Create a queue to perform level order traversal.
    queue<pair<Node *, int>> q;
    // Initialize variables to keep track of the maximum and minimum horizontal distances.
    int max_h_dist = INT_MIN;
    int min_h_dist = INT_MAX;

    // Check if the root is NULL, and return an empty result if it is.
    if (root == NULL)
        return result;
    
    // Push the root node with a horizontal distance of 0 into the queue.
    q.push({root, 0});

    // Perform level order traversal.
    while (!q.empty()) {
        // Get the front element from the queue.
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *node = temp.first;  // Extract the node from the pair.
        int h_dist = temp.second;  // Extract the horizontal distance from the pair.

        // Update the maximum and minimum horizontal distances encountered so far.
        max_h_dist = max(max_h_dist, h_dist);
        min_h_dist = min(min_h_dist, h_dist);

        // Store the node's data in the map at its horizontal distance.
        umap[h_dist].push_back(node->data);

        // If there is a left child, enqueue it with a decremented horizontal distance.
        if (node->left != NULL)
            q.push({node->left, h_dist - 1});

        // If there is a right child, enqueue it with an incremented horizontal distance.
        if (node->right != NULL)
            q.push({node->right, h_dist + 1});
    }

    // Traverse the map from the minimum horizontal distance to the maximum,
    // and add the nodes to the result vector in vertical order.
    for (int i = min_h_dist; i <= max_h_dist; ++i) {
        for (auto x : umap[i])
            result.push_back(x);
    }

    // Return the vector containing nodes in vertical order.
    return result;
}


/*
Diameter of a Binary Tree
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 
The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 
*/

int find_diameter(Node *root, int &max_diameter) {
    // Base case: If the current node is NULL, return 0.
    if (root == NULL)
        return 0;
    
    // Recursively calculate the height of the left and right subtrees.
    int left_height = find_diameter(root->left, max_diameter);
    int right_height = find_diameter(root->right, max_diameter);
    
    // Update the max_diameter with the maximum of the current max_diameter,
    // and the sum of left_height, right_height, and 1 (for the current node).
    max_diameter = max(max_diameter, left_height + right_height + 1);
    
    // Return the maximum height of the left and right subtrees + 1 for the current node.
    return max(left_height, right_height) + 1;
}

int diameter(Node* root) {
    int max_diameter = 0;
    
    // Handle the case where the root is NULL.
    if (root == NULL)
        return max_diameter;
    
    // Call the recursive function to find the diameter.
    find_diameter(root, max_diameter);
    
    // Return the maximum diameter found.
    return max_diameter;
}

/*
Level order traversal in spiral form
Given a binary tree and the task is to find the spiral order traversal of the tree.

Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right. 
*/
vector<int> findSpiral(Node *root)
{
    // Initialize the result vector to store the spiral order traversal.
    vector<int> result;
    int level = 0;  // Initialize the level indicator.

    // Check if the root is NULL, and return an empty result if it is.
    if (root == NULL)
        return result;

    // Create a queue for level order traversal and enqueue the root.
    queue<Node *> q;
    q.push(root);

    // Perform level order traversal with a spiral order twist.
    while (!q.empty()) {
        vector<int> sub_result;  // Create a vector to store nodes at the current level.
        int len = q.size();  // Get the number of nodes at the current level.
        ++level;  // Increment the level.

        // Process nodes at the current level.
        for (int i = 0; i < len; ++i) {
            Node *temp = q.front();  // Get the front node from the queue.
            q.pop();

            sub_result.push_back(temp->data);  // Add the node's data to sub_result.

            // Enqueue the left and right children if they exist.
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }

        // Reverse the sub_result vector if the level is odd (for the spiral effect).
        if (level % 2 != 0)
            reverse(sub_result.begin(), sub_result.end());

        // Add nodes from sub_result to the final result vector.
        for (auto x : sub_result)
            result.push_back(x);
    }

    // Return the result vector containing nodes in spiral order.
    return result;

    
   
}

/*
Recursive method for Level order traversal in spiral form
*/

// Recursive function to traverse the binary tree in a spiral order and store the nodes in a map.
void find_spiral_order(Node *root, unordered_map<int, vector<int>> &umap, int height, int &max_height) {
    
    max_height = max(max_height, height);  // Update the maximum height encountered so far.
    umap[height].push_back(root->data);    // Store the node's data in the corresponding level of the map.
    
    if (root->left != NULL) 
        find_spiral_order(root->left, umap, height + 1, max_height);  // Recursively traverse the left subtree.
    
    if (root->right != NULL)
        find_spiral_order(root->right, umap, height + 1, max_height);  // Recursively traverse the right subtree.
}

// Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root) {
   unordered_map<int, vector<int>> umap;  // Create a map to store nodes at different levels.
   vector<int> result;  // Initialize the result vector to store the spiral order traversal.
   int max_height = 0;  // Initialize the maximum height.

   if (root == NULL)
    return result;  // If the root is NULL, return an empty result.

   // Call the recursive function to traverse the tree and populate the map and update max_height.
   find_spiral_order(root, umap, 1, max_height);
   
   for (int i = 1; i <= max_height; ++i) {
        if (i % 2 != 0) {
            // Insert elements in reverse order when the level is odd (spiral effect).
            for (int j = umap[i].size() - 1; j >= 0; --j)
                result.push_back(umap[i][j]);
        } else {
            // Insert elements in regular order when the level is even.
            for (auto x : umap[i])
                result.push_back(x);
        }
    }
    
    return result;  // Return the result vector containing nodes in spiral order.
}


/*
 Level order traversal in spiral form Using Stacks
*/
// Function to return a list containing the level order traversal in a spiral form.
vector<int> findSpiral(Node *root)
{
    vector<int> result;  // Initialize the result vector to store the spiral order traversal.
    int level = 0;  // Initialize a level counter.

    if (root == NULL)
        return result;  // If the root is NULL, return an empty result.

    stack<Node *> s1;  // Create two stacks, s1 and s2, for alternating levels.
    stack<Node *> s2;
    
    s1.push(root);  // Push the root node onto s1 to start the traversal.

    // Continue the traversal as long as either stack s1 or s2 is not empty.
    while (!s1.empty() || !s2.empty()) {
        
        // Traverse nodes on the current level from left to right.
        while (!s1.empty()) {
            Node *temp = s1.top();  // Get the top node from stack s1.
            s1.pop();  // Pop the node from stack s1.
            result.push_back(temp->data);  // Add the node's data to the result vector.

            // Push the right child onto stack s2 (if it exists) before the left child.
            if (temp->right != NULL)
                s2.push(temp->right);
            if (temp->left != NULL)
                s2.push(temp->left);
        }
        
        // Traverse nodes on the current level from right to left.
        while (!s2.empty()) {
            Node *temp = s2.top();  // Get the top node from stack s2.
            s2.pop();  // Pop the node from stack s2.
            result.push_back(temp->data);  // Add the node's data to the result vector.

            // Push the left child onto stack s1 (if it exists) before the right child.
            if (temp->left != NULL)
                s1.push(temp->left);
            if (temp->right != NULL)
                s1.push(temp->right);
        }
    }
    
    return result;  // Return the result vector containing nodes in spiral order.
}

/*
Connect Nodes at Same Level
Given a binary tree, connect the nodes that are at same level. 
You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values.
 Your function should set these pointers to point next right for each node.
*/

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
};

void connect(Node *root)
{
    // Function to connect nodes at the same level in a binary tree
    if (root == NULL)
        return;  // If the root is NULL, there's nothing to connect

    queue<Node *> q;  // Create a queue for level order traversal
    q.push(root);     // Enqueue the root node
    Node *prev = NULL; // Initialize a pointer to the previous node

    while (!q.empty()) {
        int len = q.size(); // Get the number of nodes at the current level
        for (int i = 0; i < len; ++i) {
            Node *temp = q.front(); // Get the front node from the queue
            q.pop();

            // Enqueue the left and right children if they exist
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);

            if (i != 0)
                prev->nextRight = temp; // Connect the previous node's nextRight pointer to the current node

            prev = temp; // Update the previous node pointer for the next iteration
        }

        prev->nextRight = NULL; // Set the nextRight pointer of the last node in the current level to NULL
    }
}
*/


/*
Binary Tree to DLL
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: H is the height of the tree and this space is used implicitly for the recursion stack.
*/

//Iterative  Method

void inorder(Node *node,vector<int> &result) {
        if(node==NULL) return;
        inorder(node->left,result);
        result.push_back(node->data);
        inorder(node->right,result);
        
    }
    Node * bToDLL(Node *root)
    {
        // your code here
        if(root==NULL ) return root;
        
        vector<int> result;
        inorder(root,result);
       
        int size=result.size();
        Node *prev=new Node(result[0]);
        Node *start=prev;
        Node *curr=prev;
        for(int i=1;i<size; ++i) {
            
            curr=new Node(result[i]);
            prev->right=curr;
            curr->left=prev;
            prev=curr;
        }
        
        curr->right=NULL;
        
        
        return start;
    
    }

//Recursive Method
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
   
 Node *prev = NULL; // Declaration of prev

Node *bToDLL(Node *root)
{
    // Base case: If the current node is NULL, return NULL.
    if (root == NULL)
        return root;

    // Recursively convert the left subtree to a doubly linked list,
    // and store the head of the left list in 'head'.
    Node *head = bToDLL(root->left);

    // If 'prev' is not NULL, it means we've already processed a node.
    if (prev != NULL)
    {
        // Link the current node's left to the previous node.
        root->left = prev;

        // Link the previous node's right to the current node.
        prev->right = root;
    }
    else
    {
        // If 'prev' is NULL, it means this is the first node we're processing,
        // so update 'head' to be the current node.
        head = root;
    }

    // Update 'prev' to the current node for the next iteration.
    prev = root;

    // Recursively convert the right subtree to a doubly linked list.

    bToDLL(root->right);

    // Return the head of the doubly linked list.
    return head;
}


};



/*
Maximum Path Sum between 2 Special Nodes
Given a binary tree in which each node element contains a number.
 Find the maximum possible path sum from one special node to another special node.

Note: Here special node is a node which is connected to exactly one different node.
*/

int maxPath(Node* root, int &maxi){
        if(root==NULL)
        return 0;
        
        if(root->left==NULL and root->right==NULL){
            return root->data;
        }
        
        int left=maxPath(root->left, maxi);
        int right=maxPath(root->right, maxi);
        
        if(root->left and root->right){
            maxi=max(maxi, left+right+root->data);
            return max(left,right)+root->data;
        }
        
        if (root->left){
            return left+root->data;
        }
        return right+root->data;
        
    }
    int maxPathSum(Node* root)
    {
        // code here
        int maxi=INT_MIN;
        int x = maxPath(root,maxi);
        if(root->left and root->right){
            return maxi;
        }
        
        return max(maxi,x);
        
    }


/* 
Given a binary tree, find the maximum path sum. 
The path may start and end at any node in the tree.

*/
int find_max_path(Node* root, int& result) {
    if (root == NULL)
        return 0;

    int left_path = find_max_path(root->left, result);
    int right_path = find_max_path(root->right, result);

    int single_path = max(max(left_path, right_path) + root->data, root->data);
    int max_path = max(single_path, left_path + right_path + root->data);

    result = max(result, max_path);

    return single_path;
}

int maxPathSum(Node* root) {
    int result = INT_MIN;

    find_max_path(root, result);

    return result;
}


/*
Serialize and Deserialize a Binary Tree
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.
Note: The structure of the tree must be maintained. Multiple nodes can have the same data.
Note : NULL is denoted by -1.
*/
void serialize_preorder(Node *node, vector<int> &data) {
        
        if(node==NULL) {
            data.push_back(INT_MIN);
            return;
        }
        
        data.push_back(node->data);
        serialize_preorder(node->left,data);
        serialize_preorder(node->right,data);
    }
    
    
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> data;
        serialize_preorder(root,data);
        return data;
    }
    
    //Function to deserialize a list and construct the tree.
    int index=0;
    Node *deSerialize_preorder(vector<int> data) {
        
        if(data.size()==index) return NULL;
        if(data[index]==INT_MIN) {
            ++index;
            return NULL;
        }
        
        Node *root=new Node(data[index]);
        ++index;
        root->left=deSerialize_preorder(data);
        root->right=deSerialize_preorder(data);
        
        return root;
        
    }
    
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       
       Node * root=deSerialize_preorder(A);
       
       return root;
    }