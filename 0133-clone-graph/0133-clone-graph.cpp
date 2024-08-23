/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node * node ,map<int,Node*> &nodeMap){
        if(nodeMap[node->val])
            return nodeMap[node->val];
        nodeMap[node->val] = new Node(node->val);
        for(auto nei:node->neighbors){
            nodeMap[node->val]->neighbors.push_back(dfs(nei,nodeMap));
        }
        return nodeMap[node->val];
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        map<int,Node*> nodeMap;
        return dfs(node,nodeMap);
    }
};