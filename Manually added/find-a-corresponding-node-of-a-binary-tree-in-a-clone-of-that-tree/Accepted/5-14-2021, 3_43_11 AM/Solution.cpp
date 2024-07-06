// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* res=nullptr;
    void in_order(TreeNode* root,TreeNode *target){
        if(root!=nullptr && res==nullptr){
            in_order(root->left,target);  
                if(root->val==target->val){
                    res=root;
                    return;
                }
            in_order(root->right,target);
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        in_order(cloned,target);
            return res;
    }
};