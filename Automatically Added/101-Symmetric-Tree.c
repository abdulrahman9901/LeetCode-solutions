/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSym(struct TreeNode* left , struct TreeNode* right){
    if(!left && !right)
        return true;
    else if(!left && right || left && !right)
        return false;
    else{
        if(left->val == right->val){
                return isSym(left->left,right->right) && isSym(left->right,right->left) ;
        }else{
            return false;
        }
    }
}
bool isSymmetric(struct TreeNode* root) {
    return isSym(root->left,root->right);
}