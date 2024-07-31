class WordDictionary {
    struct Node {
        char val ;
        bool eos;
        array<Node* , 26> childs; 
        Node (char val):val(val),eos(false),childs{nullptr}{}
    };
    Node * root; 

    bool wordSearch(string word , int index , Node * node){
        if(!node) return false;
        if(index >= word.length()) return node->eos;

        if(word[index] == '.'){
            for(auto child : node->childs){
                if(wordSearch(word,index+1,child)){
                    return true;
                }
            }
            return false;
        }else{
            return wordSearch(word,index+1,node->childs[word[index] - 'a']);
        }
        return false;
    };
public:
    WordDictionary() {
        root = new Node('/');
    }  
    void addWord(string word) {
        Node * curr =  root;
        for(int i = 0 ; i < word.length() ;++i){
            if(curr->childs[word[i] - 'a'] == nullptr){
                curr->childs[word[i] - 'a'] = new Node(word[0]);
            }
            curr = curr->childs[word[i] - 'a'];
        }
        curr->eos = true; 
    }
    
    bool search(string word) {
       return wordSearch(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */