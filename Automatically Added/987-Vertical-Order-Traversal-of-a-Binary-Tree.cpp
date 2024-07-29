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
    void verticalTraversalHelper(TreeNode* root , map<int,map<int,multiset<int>>> &vhMap , int vLvl ,
    int hLvl )
    {
        if(!root)
            return;
        vhMap[vLvl][hLvl].insert(root->val);
        verticalTraversalHelper(root->left,vhMap,vLvl-1,hLvl+1);
        verticalTraversalHelper(root->right,vhMap,vLvl+1,hLvl+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         map<int,map<int,multiset<int>>> vhMap;
        vector<vector<int>> res;
        verticalTraversalHelper(root,vhMap,0,0);

        for(auto m : vhMap){
            std::vector<int> column;
            for(auto values : m.second){
                column.insert(column.end(), values.second.begin(), values.second.end());
            }
            res.push_back(column);
        }

        return res;
    }
};