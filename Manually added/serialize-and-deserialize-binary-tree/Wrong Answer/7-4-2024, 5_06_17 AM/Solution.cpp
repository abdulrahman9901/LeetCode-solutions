// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str ;
        if(root == nullptr)
            return "null";
        else 
            str = to_string(root->val);

        return str +","+serialize(root->left)+","+ serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        stringstream sstream(data);
        string tmp;
        TreeNode* tempNode ;
        char delim = ',';
        while(std::getline(sstream, tmp, delim)) {
            tempNode = nullptr;
            if(tmp != "null")
                tempNode = new TreeNode(stoi(tmp));
            nodes.push_back(tempNode);     
            }
        for(int i = 0 ; i < nodes.size() ; ++i){
            if(!nodes[i])
                continue;

            nodes[i]->left = nodes[i+1];

            if(nodes[i]->left){
                if(i + 4 < nodes.size())
                    nodes[i]->right = nodes[i+4];
            }else{
                nodes[i]->right = nodes[i+2];
            }     
        }
        
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));