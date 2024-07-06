// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    void addNode(int x,TreeNode* &root){
        if(root==nullptr){
            root=new TreeNode(x);
        }
        else{
        TreeNode* current=root,*prev=root;
        while(current!=nullptr){
            if(x > current->val){
                prev=current;
                current=current->right;
                if(!current){
                    prev->right=new TreeNode(x);
                    break;
                }
            }
            else{
                 prev=current;
                 current=current->left;
                if(!current){
                    prev->left=new TreeNode(x);
                    break;
                }
            }
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
            TreeNode* root;
        for(int i=0;i<preorder.size();++i){
            addNode(preorder[i],root);
        }
        return root;
    }
};