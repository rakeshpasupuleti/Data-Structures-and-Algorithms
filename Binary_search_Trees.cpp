#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <queue>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
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
bool validate_tree(Node *root, int min_val, int max_val)
{

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
bool isBST(Node *root)
{

    // Call the validate_tree function with the root of the tree and initial range
    // values of INT_MIN (negative infinity) for 'min_val' and INT_MAX (positive infinity)
    // for 'max_val'. This ensures that the entire tree is initially checked for BST validity.
    return validate_tree(root, INT_MIN, INT_MAX);
}

/*
Lowest Common Ancestor in a BST
Given a Binary Search Tree (with all values unique) and two node values n1 and n2 (n1!=n2).
Find the Lowest Common Ancestors of the two nodes in the BST.

*/

Node *LCA(Node *root, int n1, int n2)
{
    /*

    //Recursive Method

     if(root==NULL)
         return NULL;
     else if( (n1 < root->data) && (n2 < root->data))
         return LCA(root->left, n1, n2);
     else if( (n1 > root->data) && (n2 > root->data))
         return LCA(root->right, n1, n2);
     else
         return root;

     */
    // Check if the root is NULL. If it is, return NULL because there's no LCA.
    if (root == NULL)
        return NULL;
    // Use a while loop to traverse the tree.
    while (root != NULL)
    {

        // If both n1 and n2 are smaller than the current node's data, move to the left subtree.
        if ((n1 < root->data) && (n2 < root->data))
            root = root->left;

        // If both n1 and n2 are greater than the current node's data, move to the right subtree.
        else if ((n1 > root->data) && (n2 > root->data))
            root = root->right;
        // If n1 and n2 are on different sides of the current node's data, this node is the LCA.
        else
            break;
    }

    return root;
}


/*
Ceil in BST
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.
*/
// Function to return the ceil of given number in BST.
int findCeil(Node *root, int input)
{

    /*
    //Recursive Method
        if(root==NULL)
            return -1;
            
        else if(root->data == input)
            return root->data;
            
        else if(root->data < input)
            return findCeil(root->right, input);
        else {
            
            int ceil_val=findCeil(root->left, input);
            
            if(ceil_val >= input )
                return ceil_val;
            else
                return root->data;
        }
    */
    int ceil_val = -1; // Initialize the result to -1 (no ceil found) initially.

    while (root != NULL)
    {
        if (root->data == input)
        {
            // If the current node's data is equal to the input, it is the ceil.
            return input;
        }
        else if (root->data > input)
        {
            // If the current node's data is greater than the input, update the ceil and move to the left subtree.
            ceil_val = root->data;
            root = root->left;
        }
        else
        {
            // If the current node's data is less than the input, move to the right subtree.
            root = root->right;
        }
    }

    return ceil_val; // Return the smallest value >= input found in the BST.
}


/*
Kth largest element in BST
Given a Binary Search Tree. 
Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.
*/

// Recursive function to find the Kth largest element in a Binary Search Tree (BST).

int kthLargest(Node *root, int &K) {
    // Check if the tree is empty.
    if (root == NULL)
        return -1; // Return -1 if the tree is empty.

    // Traverse the right subtree to find the largest elements first.
    int temp = kthLargest(root->right, K);
    
    // If a valid result (temp) is found in the right subtree, return it immediately.
    if (temp != -1)
        return temp;

    // Decrement K, representing the Kth largest element we are searching for.
    --K;

    // If K reaches 0, it means we have found the Kth largest element in the current node.
    if (K == 0)
        return root->data;

    // If we haven't found the Kth largest element yet, continue searching in the left subtree.
    return kthLargest(root->left, K);
}


/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.
*/

// Define a structure to store information about subtrees.
struct Result {
    int min_value; // Minimum value in the subtree.
    int max_value; // Maximum value in the subtree.
    bool isBST;    // Whether the subtree is a valid BST.
    int size;      // Size of the largest BST in the subtree.
};

// Function to find the largest BST in the tree rooted at 'root'.
Result findLargestBST(Node* root) {
    // Base case: If the current node is null, return a Result indicating an empty tree.
    if (root == nullptr) {
        return {INT_MAX, INT_MIN, true, 0};
    }

    // Recursively find Results for the left and right subtrees.
    Result left = findLargestBST(root->left);
    Result right = findLargestBST(root->right);

    // Check if the current node and its subtrees form a valid BST.
    if (left.isBST && right.isBST && root->data > left.max_value && root->data < right.min_value) {
        // If it's a valid BST, compute the size of the BST and update Result.
        int size = left.size + right.size + 1;
        return {min(left.min_value, root->data), max(right.max_value, root->data), true, size};
    } else {
        // If it's not a valid BST, set isBST to false and return the larger size of left and right subtrees.
        return {INT_MIN, INT_MAX, false, max(left.size, right.size)};
    }
}

// Function to find and return the size of the largest BST in the tree.
int largestBst(Node* root) {
    // Call findLargestBST to get the Result for the entire tree.
    Result result = findLargestBST(root);
    // Return the size of the largest BST found.
    return result.size;
}

/*
Merge two BST 's
Given two BSTs, return elements of both BSTs in sorted form.
*/

void inorder(Node *root, vector<int> &result) {
    if (root == NULL)
        return;

    // Visit the left subtree.
    inorder(root->left, result);

    // Add the current node's data to the result vector.
    result.push_back(root->data);

    // Visit the right subtree.
    inorder(root->right, result);
}

// Merge two BSTs represented by root1 and root2 into a single sorted vector.
vector<int> merge(Node *root1, Node *root2) {
    // Create vectors to store the in-order traversal results of the two trees.
    vector<int> res1;
    vector<int> res2;

    // Perform in-order traversal on both trees to populate the vectors.
    inorder(root1, res1);
    inorder(root2, res2);

    // Create a vector to store the merged result.
    vector<int> result;

    // Get the sizes of the two vectors.
    int n = res1.size();
    int m = res2.size();

    // Initialize pointers for the two vectors.
    int i = 0, j = 0;

    // Merge the two sorted vectors into a single sorted vector.
    while (i < n && j < m) {
        if (res1[i] < res2[j]) {
            result.push_back(res1[i]);
            ++i;
        } else {
            result.push_back(res2[j]);
            ++j;
        }
    }

    // Add any remaining elements from res1.
    while (i < n) {
        result.push_back(res1[i]);
        ++i;
    }

    // Add any remaining elements from res2.
    while (j < m) {
        result.push_back(res2[j]);
        ++j;
    }

    // Return the merged and sorted vector.
    return result;
}


//Method2
// Merge two Binary Search Trees (BSTs) represented by root1 and root2 into a single sorted vector.
vector<int> merge(Node *root1, Node *root2) {
    // Create two stacks to perform in-order traversal on both trees.
    stack<Node*> s1;
    stack<Node*> s2;
    
    // Create a vector to store the merged result.
    vector<int> result;
    
    // Temporary node pointer for processing nodes.
    Node* temp;

    // Perform an in-order traversal of both trees using stacks.
    while (root1 || root2 || !s1.empty() || !s2.empty()) {
        // Traverse the left subtree of root1 and push nodes onto stack s1.
        while (root1 != NULL) {
            s1.push(root1);
            root1 = root1->left;
        }
        
        // Traverse the left subtree of root2 and push nodes onto stack s2.
        while (root2 != NULL) {
            s2.push(root2);
            root2 = root2->left;
        }

        // Compare the top nodes of both stacks and push the smaller one into the result.
        if (s2.empty() || (!s1.empty() && (s1.top()->data <= s2.top()->data))) {
            temp = s1.top();
            s1.pop();
            result.push_back(temp->data);
            root1 = temp->right;
        } else {
            temp = s2.top();
            s2.pop();
            result.push_back(temp->data);
            root2 = temp->right;
        }
    }

    // Return the merged and sorted vector.
    return result;
}


/*
Sorted Array to BST
Given a sorted array. Convert it into a Height balanced Binary Search Tree (BST).
 Find the preorder traversal of height balanced BST. 
 If there exist many such balanced BST consider the tree whose preorder is lexicographically smallest.
Height balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

*/
// Pre-order traversal of a binary tree to collect elements in a specific order.
void preorder(Node* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }

    // Visit the current node and add its data to the result vector.
    result.push_back(root->data);

    // Recursively traverse the left subtree.
    preorder(root->left, result);

    // Recursively traverse the right subtree.
    preorder(root->right, result);
}

// Recursive function to construct a Height Balanced Binary Search Tree (BST) from a sorted array.
Node* constructBST(vector<int>& nums, int low, int high) {
    if (low > high) {
        return nullptr; // Base case: The root is nullptr.
    } else {
        int mid = (low + high) / 2;
        Node* root = new Node(nums[mid]); // Create a new node for the current root.
        
        // Recursively build the left and right subtrees of the current root.
        root->left = constructBST(nums, low, mid - 1);
        root->right = constructBST(nums, mid + 1, high);

        return root;
    }
}

// Main function to convert a sorted array into a Height Balanced Binary Search Tree (BST).
vector<int> sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) {
        return {}; // If the input array is empty, return an empty vector.
    }

    Node* root = constructBST(nums, 0, n - 1);

    vector<int> result;

    // Perform pre-order traversal to collect elements in the desired order.
    preorder(root, result);

    return result; // Return the vector containing the pre-order traversal of the BST.
}

