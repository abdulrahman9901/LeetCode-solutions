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
    void addRow (TreeNode* node, int val, int depth , TreeNode* parent , char side){
        if(depth==1 ){
            TreeNode * right;
            TreeNode * left ;
            if(side == 'R')
            {   
                right = new TreeNode(val,nullptr,parent->right); 
                parent->right = right;
            }
            else if (side == 'L')
            {   cout<<node->val<<endl;
                left = new TreeNode(val,parent->left,nullptr);
                parent->left = left;
             }
        }
        else if (depth==2 && !node->right && !node->left )
        {
            TreeNode * right;
            TreeNode * left ;
            right = new TreeNode(val); 
            left = new TreeNode(val);
            node->left = left;
            node->right = right;
        }else {
            if(node->right)
                addRow(node->right,val,depth-1,node,'R');
            if(node->left)
                addRow(node->left,val,depth-1,node,'L');
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        addRow(root,val,depth,root,'N');
        return root;
    }
};