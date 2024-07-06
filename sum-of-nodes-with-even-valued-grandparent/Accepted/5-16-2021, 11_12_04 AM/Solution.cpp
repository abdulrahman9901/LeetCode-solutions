// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent

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
    int sum=0;
    void sumtree(TreeNode* root,TreeNode* parent){
        if(root==nullptr)
            return;
        if(parent!=nullptr){
            if((parent->val)%2 ==0){
            if(root->left!=nullptr)
                 sum+=root->left->val;
            if(root->right!=nullptr)
                sum+=root->right->val;
            }
        }
            sumtree(root->left,root);
            sumtree(root->right,root);
    }
    int sumEvenGrandparent(TreeNode* root) {
        sumtree(root,nullptr);
        return sum;
    }
};