// https://leetcode.com/problems/subtree-of-another-tree

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
    bool foundSub(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr || subRoot == nullptr){
            return false;
        }else 
        }else{
            cout<<root->val <<" : "<<subRoot->val<<endl;
            if(root->val == subRoot->val)
                return foundSub(root->left,subRoot->left) && foundSub(root->right,subRoot->right);
            else 
                return false;
        }
    } 
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot && root)
            if(root->val == subRoot->val){
                auto f = foundSub(root,subRoot);
                cout<<root->val <<" : "<<subRoot->val<<" -> "<<f<<endl;
                return f;
            }
            else 
                return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        else
            return false;
    }
};