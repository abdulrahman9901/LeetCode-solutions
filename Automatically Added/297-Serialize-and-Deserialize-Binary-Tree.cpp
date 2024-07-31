/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void helper(TreeNode* root , string & s){
        string val = root ? std::to_string(root->val) : \N\;
        s += \,\ + val;
        if(!root)
            return;
        helper(root->left,s);
        helper(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial;
        helper(root,serial);
        return serial.substr(1);
    }

    TreeNode* buidTree(vector <string> &s, int &index) {
        if (index >= s.size() || s[index] == \N\) {
            index++;
            return nullptr;
        }
        
        TreeNode* Node = new TreeNode(stoi(s[index++]));
        Node->left = buidTree(s,index);
        Node->right = buidTree(s,index);
        return Node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector <string> tokens;
        // stringstream class check1
        stringstream serialData(data);
        
        string intermediate;
        
        // Tokenizing w.r.t. space ' '
        while(getline(serialData, intermediate, ','))
        {   
            tokens.push_back(intermediate);
        }
        int index = 0;
        return buidTree(tokens,index);
    }
};
