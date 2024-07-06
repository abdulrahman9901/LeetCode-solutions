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
     vector<vector<int>> v;
public:
    int getdepth(TreeNode* root){
        if(root==nullptr)
            return 0;
        return max(getdepth(root->left),getdepth(root->right))+1;
    }
    void level(TreeNode* root,int index){
        if(root==nullptr)
            return;
        v[index].push_back(root->val);
        level(root->left,index-1);
        level(root->right,index-1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth=getdepth(root);
        v.assign(depth,{});
        level(root,depth-1);
        return v;
    }
};
