#include<iostream>
using namespace std;
#include<vector>
#include <algorithm>
#include<unordered_map>
#include <numeric>
#include <stack>
#include<queue>

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
Check for BST
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
// This function is used to validate whether a binary tree is a Binary Search Tree (BST).
// It checks that the values in the tree's nodes satisfy the BST property.
bool validate_tree(Node *root, int min_val, int max_val) {
    
    // If the current node is NULL (empty), it doesn't violate the BST property,
    // so we return true.
    if (root == NULL)
        return true;
    
    // Check if the data value of the current node is within the valid range defined
    // by 'min_val' and 'max_val'. If it's not, return false, indicating that this
    // tree is not a BST.
    if (!(root->data > min_val && root->data < max_val))
        return false;
    
    // Recursively validate the left and right subtrees of the current node.
    // The left subtree should have values within the range (min_val, root->data),
    // and the right subtree should have values within the range (root->data, max_val).
    bool left_tree = validate_tree(root->left, min_val, root->data);
    bool right_tree = validate_tree(root->right, root->data, max_val);
    
    // If both the left and right subtrees are BSTs, return true, indicating
    // that the entire tree is a BST.
    return (left_tree && right_tree);
}

// This is the entry point for checking whether a given tree is a Binary Search Tree.
bool isBST(Node* root) {
    
    // Call the validate_tree function with the root of the tree and initial range
    // values of INT_MIN (negative infinity) for 'min_val' and INT_MAX (positive infinity)
    // for 'max_val'. This ensures that the entire tree is initially checked for BST validity.
    return validate_tree(root, INT_MIN, INT_MAX);
}


