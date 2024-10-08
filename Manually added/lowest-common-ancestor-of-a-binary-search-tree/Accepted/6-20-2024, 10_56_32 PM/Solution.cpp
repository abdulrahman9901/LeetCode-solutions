// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return root;
        else if((p->val >= root->val && q->val <= root->val)
            || (q->val >= root->val && p->val <= root->val) )
            return root;
        else {
            auto temp =lowestCommonAncestor(root->left,p,q);
            if(!temp)
                temp = lowestCommonAncestor(root->right,p,q); 
            return temp;
        }
    }
};