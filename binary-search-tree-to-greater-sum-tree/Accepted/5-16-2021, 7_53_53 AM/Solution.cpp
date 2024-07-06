// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

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
    int x=0;
public:
    void conv(TreeNode* root){
        if(root==nullptr)
            return ;
      conv(root->right);
       root->val+=x;
        x=root->val;
       conv(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
         conv(root);
        return root;
    }
};