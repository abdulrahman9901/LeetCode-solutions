class Trie {
    struct Node {
        char val;
        bool eos;
        array<Node*, 26> childs;
        Node(char val , bool eos ):val(val),eos(eos),childs({nullptr}){}
    };
    Node *root;
public:
    Trie() {
        root = new Node(' ',false);
    }
    
    void insert(string word) {
        Node * current = root;
        for(char c : word){
            if(current->childs[c - 'a'] == nullptr){
                current->childs[c - 'a'] = new Node(c,false);
            }
            current = current->childs[c - 'a'];
        }
        current->eos = true;
    }
    
    bool search(string word) {
        Node * current = root;
        for(char c : word){
            if(current->childs[c - 'a'] == nullptr){
                return false;
            }
            current = current->childs[c - 'a'];
        }
        return current->eos;
    }
    
    bool startsWith(string prefix) {
        Node * current = root;
        for(char c : prefix){
            if(current->childs[c - 'a'] == nullptr){
                return false;
            }
            current = current->childs[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */