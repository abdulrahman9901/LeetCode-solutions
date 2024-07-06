// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree

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
    void in_order_noRepeat(TreeNode* root){
        if(root!=nullptr){
            in_order_noRepeat(root->left);                
            if(v.size()==0 || v.end()==find(v.begin(),v.end(),root->val))
                v.push_back(root->val);
            in_order_noRepeat(root->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        in_order_noRepeat(root);
        sort(v.begin(),v.end());
        if(v.size()<2)
            return -1;
        return v[1];
    }
};