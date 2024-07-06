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
    map<int,vector<int>> m;
    void level(TreeNode* root,int index){
        if(root==nullptr)
            return;
        m[index].push_back(root->val);
        level(root->left,index+1);
        level(root->right,index+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        level(root,0);
        for(auto map=m.rbegin();map!=m.rend();++map)
            v.push_back(map->second);
        return v;
    }
};
