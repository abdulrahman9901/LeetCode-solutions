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
    bool isValid(TreeNode* node ,int min,int max ,string pos){
        if(!node)
            return true;   
        if((pos  == "H" )|| (node->val < max && node->val > min))
            return isValid(node->left,INT_MIN,max,"L") && 
                   isValid(node->right,max,INT_MAX,"R");
        else
            return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,root->val,root->val,"H");
    }
};