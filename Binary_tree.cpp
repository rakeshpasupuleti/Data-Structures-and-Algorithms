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

