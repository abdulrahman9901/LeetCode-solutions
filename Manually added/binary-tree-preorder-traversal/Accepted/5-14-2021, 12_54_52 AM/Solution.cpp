// https://leetcode.com/problems/binary-tree-preorder-traversal

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
      vector<int> v;
    void pre_order(TreeNode* root){
        if(root!=nullptr){
            v.push_back(root->val);
            pre_order(root->left);
            pre_order(root->right);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
          pre_order(root);
        return v;
    }
};