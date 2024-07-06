// https://leetcode.com/problems/longest-univalue-path

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
    int path=0;
    vector<int>v;
    void traverse(TreeNode* root,int val){
        if(root==nullptr)
            return;
        else if(root->val==val){
            path+=1;
        }else{
            val=root->val;
            v.push_back(path);
            if(path)
                path-=1;
        }
    traverse(root->left,val);
    traverse(root->right,val);
    }
    int longestUnivaluePath(TreeNode* root) {
        traverse(root,1001);
        path=max(*max_element(v.begin(), v.end()),path);
        return path;
    }
};