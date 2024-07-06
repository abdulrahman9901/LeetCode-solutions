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
    bool isValid(TreeNode* node,long min,long max ){
        if(!node)
            return true;   
        if(node->val < max && node->val > min){
            return isValid(node->left,min,node->val) && 
                   isValid(node->right,node->val,max);
        }
        else
            return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,(long)INT_MIN-1,(long)INT_MAX+1);
    }
};