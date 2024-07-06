// https://leetcode.com/problems/n-ary-tree-level-order-traversal

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
public:
    void Level_Order(Node *root,vector<vector<int>>&res,int index){
        if(index>= res.size())
            res.push_back(vector<int>(1,root->val));
        else
            res[index].push_back(root->val);
        for(auto ele:root->children)
              Level_Order(ele,res,index+1);
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(root!=nullptr)
            Level_Order(root,res,0);
        return res;
    }
};