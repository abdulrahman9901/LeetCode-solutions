// https://leetcode.com/problems/sum-of-left-leaves

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
    void helperfunction(TreeNode* node , char side,int &sum){
        if(side == 'l' && node->left==nullptr && node->right==nullptr)
            sum+=node->val;
        else if (!node->left && !node->right)
            return;
        else if (!node->left && node->right)
            helperfunction(node->right, 'r',sum);
        else if (!node->right && node->left)
            helperfunction(node->left, 'l',sum);
        else {
            helperfunction(node->right, 'r',sum);
            helperfunction(node->left, 'l',sum);
        }
    }
        
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        helperfunction(root,'root',sum);
        return sum;
    }
};