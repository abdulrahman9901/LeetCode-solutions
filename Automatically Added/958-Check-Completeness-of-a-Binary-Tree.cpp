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
    int countNodes(TreeNode* root){
        if(!root)
            return 0;
        else 
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool isCT(TreeNode* root , int index , int nodesCount){
        if(!root)
            return true;
        if(index >= nodesCount)
            return false;
        
        return isCT(root->left , 2*index+1,nodesCount) && isCT(root->right , 2*index+2,nodesCount); 
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int nodesCount = countNodes(root);
        return isCT(root,0,nodesCount);
    }
};