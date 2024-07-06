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
    void level_order(TreeNode* root,int index,bool alt){
        if(root==nullptr)
            return;
        m[index].push_back(root->val);
        if(alt){
            level_order(root->left,index+1,!alt);
            level_order(root->right,index+1,!alt);
        }else{
            level_order(root->right,index+1,!alt);
            level_order(root->left,index+1,!alt);
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        level_order(root,0,false);
         vector<vector<int>>v;
        for(auto iter=m.begin();iter!=m.end();++iter)
            v.push_back(iter->second);
        return v;
    }
};