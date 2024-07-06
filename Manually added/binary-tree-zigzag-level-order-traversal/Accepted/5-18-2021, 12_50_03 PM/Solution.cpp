// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    map<int,vector<int>> m;
    void level_order(TreeNode* root,int index){
        if(root==nullptr)
            return;
        m[index].push_back(root->val);
        level_order(root->left,index+1);
        level_order(root->right,index+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        level_order(root,0);
        bool alt=false;
         vector<vector<int>>v;
        for(auto iter=m.begin();iter!=m.end();++iter){
            auto v1=iter->second;
            if(alt)
            reverse(v1.begin(),v1.end());
          
            v.push_back(v1);
            alt=!alt;
        }
        return v;
    }
};