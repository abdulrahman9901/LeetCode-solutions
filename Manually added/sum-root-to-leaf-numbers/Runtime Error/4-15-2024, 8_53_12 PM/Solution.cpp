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
    int sumNumbershelper(TreeNode* node , int sum) {
        // if(!node)
        //     return sum;
        if(!node->right && !node->left){
            return sum + node->val;
        }
        else {
            return sumNumbershelper(node->right,(sum+node->val)*10) + sumNumbershelper(node->left,(sum+node->val)*10);
        }
    }
    int sumNumbers(TreeNode* root) {
        return sumNumbershelper(root,0);
    }
};