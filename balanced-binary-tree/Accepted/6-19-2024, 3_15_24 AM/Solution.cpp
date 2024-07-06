// https://leetcode.com/problems/balanced-binary-tree

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
    int edges(TreeNode* root, int &diff){
        if(root == nullptr)
            return 0;
        else {
            int leftE = edges(root->left,diff);
            int rightE = edges(root->right,diff);
            diff = max(diff,abs(leftE-rightE));
            cout<<diff<<endl;
            return max(leftE,rightE)+1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        else {
            int diff = 0;
            edges(root,diff);
            return diff <=1;
        }
    }
};