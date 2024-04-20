/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.


Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []*/
#include <algorithm> // for std::min

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr; // Base case: empty tree

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key); // Search in the left subtree
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key); // Search in the right subtree
        }
        else
        {
            // Node with key found, perform deletion
            if (!root->left)
            {
                TreeNode *rightChild = root->right;
                delete root;
                return rightChild; // No left child, replace with right child
            }
            else if (!root->right)
            {
                TreeNode *leftChild = root->left;
                delete root;
                return leftChild; // No right child, replace with left child
            }
            else
            {
                // Node has two children
                TreeNode *minRight = findMin(root->right);            // Find minimum value in right subtree
                root->val = minRight->val;                            // Replace node's value with minimum value
                root->right = deleteNode(root->right, minRight->val); // Delete the minimum value node
            }
        }
        return root;
    }

private:
    TreeNode *findMin(TreeNode *node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }
};
