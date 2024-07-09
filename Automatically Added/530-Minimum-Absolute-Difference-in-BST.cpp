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
    void getInOrder(TreeNode* root , vector<int>&inOrder){
        if(root == nullptr)
            return;
        getInOrder(root->left,inOrder);
        inOrder.push_back(root->val);
        getInOrder(root->right,inOrder);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> inOrder ;
        int min = INT_MAX;
        getInOrder(root ,inOrder);
        for(int i = 1 ; i < inOrder.size() ; ++i){
            if(abs(inOrder[i] - inOrder[i-1]) < min)
                min = abs(inOrder[i] - inOrder[i-1]);
        }
        return min;
    }
};