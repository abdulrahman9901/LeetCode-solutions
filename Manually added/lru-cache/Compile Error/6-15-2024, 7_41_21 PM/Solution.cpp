// https://leetcode.com/problems/lru-cache

class Node {
    public:
    int key ;
    int value ;
    Node * next;
    Node * prev;

    Node(int key , int value , Node * next = nullptr,Node * prev = nullptr){
        this->key = key;
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
  
};
class LRUCache {
    Node * tail;
    Node * head;
    int capacity ;
    map<int ,Node*> cache;

    void moveToHead(Node * node){
        if(node->next){
            node->next->prev =  node->prev;
            node->next =  head;
            node->prev =  nullptr;
        }else {
            
        }
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = nullptr;
        this->tail = nullptr;
    }
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */