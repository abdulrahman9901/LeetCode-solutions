// https://leetcode.com/problems/deepest-leaves-sum

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
    /*struct node{
        int val;
        int level;
        node(int val,int lvl):val(val),level(lvl){}
    }
    vector<node>v;
    */
    map<int,int>m;
    void dfs(TreeNode* root,int lvl){
        if(root!=nullptr){
            //v.push_back(node(root->val,lvl));
            m[lvl]+=root->val;
            dfs(root->left,lvl+1);
            dfs(root->right,lvl+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        if(m.size()!=0)
            return m[m.size()-1];
        return 0;
    }
};