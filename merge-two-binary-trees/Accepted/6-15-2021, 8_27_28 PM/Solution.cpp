// https://leetcode.com/problems/merge-two-binary-trees

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
    void build (TreeNode* root1, TreeNode* root2,TreeNode* &root3){
        if(root1!=nullptr & root2!=nullptr ){
            root3=new TreeNode (root1->val + root2->val);
            build(root1->left,root2->left,root3->left);
            build(root1->right,root2->right,root3->right);
        }
        else if(root1!=nullptr ){
                root3=new TreeNode (root1->val);
            build(root1->left,nullptr,root3->left);
            build(root1->right,nullptr,root3->right);
        }
        else if(root2!=nullptr ){
                root3=new TreeNode (root2->val);
            build(nullptr,root2->left,root3->left);
            build(nullptr,root2->right,root3->right);
        }else{
            return;
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root3=nullptr;
        build(root1,root2,root3);
        return root3;
    }
};