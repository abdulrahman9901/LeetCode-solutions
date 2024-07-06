// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    void build(){

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* Node = nullptr;
        unordered_map<int,TreeNode*> treeMap;
        for(int i = 0 ; i < preorder.size();++i){
            treeMap[preorder[i]] = new TreeNode(preorder[i]);
        }
        for(auto node : treeMap){
            int posInorder = find(inorder.begin(),inorder.end(),node.first) - inorder.begin();
            int posPreorder = find(preorder.begin(),preorder.end(),node.first) - preorder.begin();
            if(pos - 2 >= 0 && ){
                node.second->left = treeMap[inorder[pos-2]];
            }else if(pos - 1 >= 0) {
                node.second->left = treeMap[inorder[pos-1]];
            }

            if(pos + 2 < preorder.size()){
                node.second->left = treeMap[inorder[pos+2]];
            }else if(pos + 1 < preorder.size()){
                node.second->left = treeMap[inorder[pos+1]];
            }

        }
        
    return treeMap[preorder[0]];
    }
};