// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int goodCount(TreeNode* root , int maxNode  ){
        if(!root)
            return 0;
        if(root->val >= maxNode){
            maxNode = root->val;
            return goodCount(root->right,maxNode) + goodCount(root->left,maxNode) + 1;
        }
        return goodCount(root->right,maxNode) + goodCount(root->left,maxNode);        
    }
public:
    int goodNodes(TreeNode* root) {
       return goodCount(root,root->val);
    }
};