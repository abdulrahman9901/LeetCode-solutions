// https://leetcode.com/problems/invert-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root && root->left && root->right){
            auto temp =  root->left;
            root->left =  root->right;
            root->right =  temp;
            auto tempNode = invertTree(root->left);
            tempNode = invertTree(root->right);
        } 
        return root;
    }
};