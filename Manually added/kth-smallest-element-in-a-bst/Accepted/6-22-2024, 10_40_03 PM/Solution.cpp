// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    void inOrder(vector<int>&tree,TreeNode* root){
        if(!root)
            return;
        inOrder(tree,root->left);
        tree.push_back(root->val);
        inOrder(tree,root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tree ;
        inOrder(tree,root);
        if(tree.size() >= k)
            return tree[k-1];
        return 0;
    }
};