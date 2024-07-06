// https://leetcode.com/problems/binary-tree-right-side-view

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
    void rightSide(TreeNode* root,vector<int> &res ,int level,int &lastLevel ){
        if(!root)
            return;
        if(lastLevel < level){
            res.push_back(root->val);
            lastLevel = level;
        }
        rightSide(root->right,res,level + 1,lastLevel);
        rightSide(root->left,res,level + 1,lastLevel);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int lastLevel=0;
        rightSide(root,res,1,lastLevel);
        return res;
    }
};