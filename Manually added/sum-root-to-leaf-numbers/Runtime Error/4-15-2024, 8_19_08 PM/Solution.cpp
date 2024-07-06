// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    void sumNumbershelper(TreeNode* node , int sum) {
        sum +=node->val;
        
        sumNumbershelper(node->right,sum * 10);
        sumNumbershelper(node->left,sum * 10);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if(root)
            sumNumbershelper(root,sum);
        return sum;
    }
};