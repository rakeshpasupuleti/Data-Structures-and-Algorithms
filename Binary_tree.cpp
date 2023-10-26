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