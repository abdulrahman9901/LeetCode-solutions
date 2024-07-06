// https://leetcode.com/problems/longest-univalue-path

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
    int path,val;
    vector<int>v;
    void traverse(TreeNode* root){
        if(root==nullptr)
            return;
        else if(root->val==val){
            path+=1;
        }else{
            val=root->val;
            v.push_back(path);
            path=0;
        }
    traverse(root->left);
        val=root->val;
    traverse(root->right);
    }
    int longestUnivaluePath(TreeNode* root) {
        traverse(root);
        return *max_element(v.begin(), v.end());
    }
};