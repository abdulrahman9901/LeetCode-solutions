// https://leetcode.com/problems/diameter-of-binary-tree

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
    int maxD(TreeNode* root , int &md){
        if(root == nullptr)
            return 0;
        else {
            int leftedges = maxD(root->left,md);
            int rightedges = maxD(root->right,md);
            md = max(md,leftedges+rightedges);
            return max(leftedges,rightedges)+1;
        }
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr || (!root->left && !root->right))
            return 0;
        int di = 0;
        maxD(root,di);
        return di;
    }
};