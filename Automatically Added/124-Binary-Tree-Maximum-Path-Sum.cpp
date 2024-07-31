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
    int helper (TreeNode* root , int &maxVal ){
        if(!root)
            return 0;

        int lval = helper(root->left, maxVal);
        lval = lval > 0 ? lval : 0 ;
        int rval = helper(root->right, maxVal);
        rval = rval > 0 ? rval : 0 ;

        int pathVal = root->val + lval + rval ;

        if(maxVal < pathVal)
            maxVal = pathVal;

        int childMax = max(lval,rval) ;

        return root->val + childMax ;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxVal = INT_MIN;
        int temp = helper(root, maxVal); 
        return maxVal;
    }
};