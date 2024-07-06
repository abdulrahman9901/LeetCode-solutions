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
    int capacity;
    map<int ,Node*> cache;

    void moveToHead(Node * node){
        if(node == nullptr || node == head)
            return;
        if (node == tail && tail != nullptr){
            tail=tail->prev;
        }
        if(node->next){
            node->next->prev =  node->prev;
        }
        if(node->prev){
            node->prev->next =  node->next;
        }
        if(head !=nullptr){
            head->prev =  node;
        }
        if(tail == nullptr){
            tail = node;
        }
        node->next =  head; 
        node->prev =  nullptr;
        head = node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = nullptr;
        this->tail = nullptr;
    }
    int get(int key) {
        moveToHead(cache[key]);
        return (cache.find(key)!=cache.end()) && cache[key] ? cache[key]->value : -1;
    }
    
    void put(int key, int value) {
        Node* temp;
         if(cache.find(key)!=cache.end() && cache[key] ){
            temp = cache[key];
            temp->value = value;          
        }else if(capacity > 0){
            temp = new Node (key,value);
            capacity--;
        }else {
            temp = tail;
            cache.erase(temp->key);
            temp->key = key ;
            temp->value = value ;
        }
        moveToHead(temp);
        cache[key]=temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */