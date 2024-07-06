// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
   /*  int to_decimal(string s,int index=0){
      if(index >= s.size())
        return 0;
      else
        return (s[index]-'0')*pow(2,index)+to_decimal(s,index+1);
    }
    */
    int sum(TreeNode* root,stack<int>s){
        if(root->left==nullptr && root->right==nullptr){
            s.push(root->val);
            int S=0,n=0;
            while(!s.empty()){
                S+=s.top()*pow(2,n++);
                s.pop();
            }
            return S;
        }
            else{
                s.push(root->val);
                return sum(root->left,s)+sum(root->right,s);
            }
    }
    int sumRootToLeaf(TreeNode* root) {
        stack<int>s;
        return sum(root,s);
    }
};