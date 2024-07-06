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
    struct node{
        int val;
        TreeNode* ref;
        node(int x,TreeNode* ref):val(x),ref(ref){}
    };
    vector<node>v;
    void in_order(TreeNode* root){
        if(root!=nullptr){
            in_order(root->left);                
            v.push_back(node(root->val,root));
            in_order(root->right);
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res=nullptr;
        in_order(cloned);
        for(int i=0;i<v.size();++i){
            if(v[i].val==target->val)
                res=v[i].ref;
        }
            return res;
    }
};