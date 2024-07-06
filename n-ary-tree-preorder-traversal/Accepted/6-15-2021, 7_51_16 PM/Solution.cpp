// https://leetcode.com/problems/n-ary-tree-preorder-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void preorder(Node* root,vector<int>& res){
        res.push_back(root->val);
        if(root->children.size()==0)
            return;
         else{
             for(auto ele:root->children)
                 preorder(ele,res);
         }
    }   
public:
    vector<int> preorder(Node* root) {
            vector<int> res;
            if(root!=nullptr)
                 preorder(root,res); 
        return res;
    }
};