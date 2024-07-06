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
    vector<int> v;
    void in_order(TreeNode* root){
        if(root!=nullptr){
            in_order(root->left);
            v.push_back(root->val);
            in_order(root->right);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        in_order(root);
        if(v.size()!=0)
            return v[k-1];
        return 0;
    }
};