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
        map<int,TreeNode*> treeMap;
        int posIn , posPre , shortage = 0;
        for(int i = 0 ; i < preorder.size();++i){
            treeMap[preorder[i]] = new TreeNode(preorder[i]);
        }
        for(int i = 0 ; i < preorder.size();++i){
            posIn = find(inorder.begin(),inorder.end(),preorder[i]) - inorder.begin();
            posPre = find(preorder.begin(),preorder.end(),preorder[i]) - preorder.begin();
            Node = treeMap[preorder[i]];
            int leftChildIndx = 2 * (posPre + 1) - shortage - 1; 
            int rightChildIndx = 2 * (posPre + 1) - shortage ;
            if(leftChildIndx < preorder.size() &&
             ( posIn - 1 >=0 && preorder[leftChildIndx] == inorder[posIn - 1] || 
               posIn - 2 >=0 && preorder[leftChildIndx] == inorder[posIn - 2]) )
                {
                    Node->left = treeMap[preorder[leftChildIndx]];
            }else {
                shortage++;
            }

            if(rightChildIndx < preorder.size() &&
             ( posIn + 1 < inorder.size() && preorder[rightChildIndx] == inorder[posIn + 1] || 
               posIn + 2 < inorder.size() && preorder[rightChildIndx] == inorder[posIn + 2]) )
                {
                    Node->right = treeMap[preorder[rightChildIndx]];
            }else {
                shortage++;
            }
        }
    return treeMap[preorder[0]];
    }
};