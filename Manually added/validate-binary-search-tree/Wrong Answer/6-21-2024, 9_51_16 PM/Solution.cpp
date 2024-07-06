// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValid(TreeNode* node ,int parent,const int rootVal ,char pos){
        if(!node)
            return true;   
        if((pos  == 'L' && node->val <= parent && node->val <= rootVal) ||
           (pos  == 'R' && node->val > parent && node->val > rootVal))
            return isValid(node->left,node->val,rootVal,'L') && isValid(node->right,node->val,rootVal,'R');
        else
            return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,root->val,root->val,'L');
    }
};