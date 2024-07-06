// https://leetcode.com/problems/increasing-order-search-tree

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
    vector<int> v;
    void in_order(TreeNode* root){
        if(root!=nullptr){
            increasingBST(root->left);
            v.push_back(root->val);
            increasingBST(root->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        in_order(root);
        if(v.size()!=0){
        TreeNode* newroot=new TreeNode(v[0]);
        TreeNode* temp=newroot;
            for(int i=1;i<v.size();++i){
                temp->right=new TreeNode(v[i]);
                temp=temp->right;
            }
            return newroot;
        }
        return root;
    }
};