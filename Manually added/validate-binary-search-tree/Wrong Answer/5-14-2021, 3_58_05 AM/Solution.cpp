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
public:
    bool helper(TreeNode* root,int min,int max){
            if (root==nullptr)
                return true;
            else if(root->val >max ||root->val < min)
                    return false;
        return helper(root->left,min,root->val) &&helper(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
         return helper(root,INT_MIN,INT_MAX);
    }
};