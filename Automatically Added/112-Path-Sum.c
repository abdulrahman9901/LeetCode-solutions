/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool checkSum(struct TreeNode* root, int targetSum) {
    if(!root)
        return false;
    if(targetSum - root->val == 0 && !root->left && !root->right)
        return true;
    return checkSum(root->left,targetSum - root->val) || checkSum(root->right,targetSum - root->val) ;
 }
bool hasPathSum(struct TreeNode* root, int targetSum) {
    return checkSum(root,targetSum);
}