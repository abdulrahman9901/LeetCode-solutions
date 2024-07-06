// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    void traverse(TreeNode* root , vector<vector<int>> &res , int level){
        if(!root)
            return;
        res[level].push_back(root->val);
        traverse(root->left,res,level+1);
        traverse(root->right,res,level+1);
    }
    int getHeight(TreeNode* root){
        if(root)
            return max(getHeight(root->right),getHeight(root->left))+1;
        else
            return 0;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> res;    
       int height = getHeight(root);
       res = vector<vector<int>>(height,vector<int>(0,0));
       traverse(root,res,0);
       return res;
    }
};