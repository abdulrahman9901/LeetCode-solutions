// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    int getdepth(TreeNode* root){
        if(root==nullptr)
            return 0;
        return max(getdepth(root->left),getdepth(root->right))+1;
    }
    void level(TreeNode* root,int index,vector<vector<int>> &v){
        if(root==nullptr)
            return;
        v[index].push_back(root->val);
        level(root->left,index-1,v);
        level(root->right,index-1,v);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth=getdepth(root);
        vector<vector<int>> v(depth,vector<int>());
        level(root,depth-1,v);
        return v;
    }
};
