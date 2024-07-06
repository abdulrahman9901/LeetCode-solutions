// https://leetcode.com/problems/maximum-binary-tree

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
    int maximum(vector<int>& arr, int st, int end) {
        int max = arr[st], indx = st;
        for (int i = st + 1; i < end; ++i) {
            if (arr[i] > max) {
                max = arr[i];
                indx = i;
            }
        }
        return indx;
    }
    void build_tree(vector<int>& nums, TreeNode* &root, int st, int ed) {
        if (st >= ed)
            return;

        int mx = maximum(nums, st, ed);
        root = new TreeNode(nums[mx]);
        build_tree(nums, root->left, st, mx);
        build_tree(nums, root->right, mx + 1, ed);
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=nullptr;
        build_tree(nums, root, 0, nums.size());
        return root;
    }
};
