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
    bool checkAncestor(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode** res){
        if(root == nullptr)
            return false;
        if(root == p || root == q){
            bool leftVal = checkAncestor(root->left,p,q,res) ;
            bool rightVal = checkAncestor(root->right,p,q,res);
            if(leftVal || rightVal){
                *res = root; 
            }
            return true ;
        }else{
            bool leftVal = checkAncestor(root->left,p,q,res) ;
            bool rightVal = checkAncestor(root->right,p,q,res);
            if(leftVal && rightVal){
                *res = root; 
            }
            return leftVal || rightVal;
        } 
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr;
        if(root)
           checkAncestor(root,p,q,&res);
        return res;
    }
};