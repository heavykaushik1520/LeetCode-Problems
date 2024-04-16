/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]*/

#include <vector>
#include <string>
#include <sstream> // For std::ostringstream

using namespace std;

/**
 * Definition for a binary tree node.
 */
/*struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root)
            dfs(root, "", paths);
        return paths;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        // Append the current node's value to the path
        path += to_string(node->val);
        
        // Check if the current node is a leaf node
        if (!node->left && !node->right) {
            paths.push_back(path);
            return;
        }
        
        // If not a leaf node, continue DFS to left and right subtrees
        if (node->left)
            dfs(node->left, path + "->", paths);
        if (node->right)
            dfs(node->right, path + "->", paths);
    }
};
