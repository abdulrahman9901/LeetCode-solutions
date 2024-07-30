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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0 )
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int rootPos = find(inorder.begin() , inorder.end() , preorder[0]) - inorder.begin() ;


        vector<int> leftPreorder (preorder.begin() + 1 , preorder.begin() + rootPos + 1);
        vector<int> rightPreorder (preorder.begin() + rootPos + 1 , preorder.end());

        vector<int> leftInorder (inorder.begin(), inorder.begin() + rootPos);
        vector<int> rightInorder (inorder.begin() + rootPos + 1 , inorder.end());

        root->left = buildTree(leftPreorder,leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;

    }
};