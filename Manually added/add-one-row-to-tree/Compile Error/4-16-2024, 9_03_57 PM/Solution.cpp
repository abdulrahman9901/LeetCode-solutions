// https://leetcode.com/problems/add-one-row-to-tree

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
    void addRow (TreeNode* root, int val, int depth){
        if(depth==1){
            TreeNode * right;
            
            if(root->right){
                right = new TreeNode(val,root->right->left,root->right->right);
            }else{
                right = new TreeNode(val);
            }
            root->right = right;
            } if (root->left) {
                TreeNode * left = new TreeNode(val,root->left->left,root->left->right);
            }else{
                TreeNode * left = new TreeNode(val);
            }
            root->right = left;

        }else {
            if(root->right)
                addRow(root->right,val,depth-1);
            if(root->left)
                addRow(root->left,val,depth-1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        addRow(root,val,depth);
        return root;
    }
};