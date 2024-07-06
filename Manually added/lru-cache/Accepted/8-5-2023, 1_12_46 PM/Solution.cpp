// https://leetcode.com/problems/lru-cache

#include <unordered_map>

class LRUCache {
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cacheMap;
    Node* head;
    Node* tail;

public:
    LRUCache(int cap) : capacity(cap), head(nullptr), tail(nullptr) {}

    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            moveToHead(cacheMap[key]); // Update LRU order
            return cacheMap[key]->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->value = value; // Update value
            moveToHead(cacheMap[key]); // Update LRU order
        } else {
            if (cacheMap.size() == capacity) {
                evictLRU();
            }
            Node* newNode = new Node(key, value);
            cacheMap[key] = newNode;
            addToHead(newNode);
        }
    }

private:
    void moveToHead(Node* node) {
        if (node == head) {
            return;
        }

        // Update the previous node's next pointer
        if (node->prev) {
            node->prev->next = node->next;
        }

        // Update the next node's prev pointer
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }

        // Update node's pointers
        node->prev = nullptr;
        node->next = head;

        // Update head's prev pointer
        if (head) {
            head->prev = node;
        }

        head = node;
    }

    void addToHead(Node* node) {
        node->prev = nullptr;
        node->next = head;
        if (head) {
            head->prev = node;
        }
        head = node;

        if (!tail) {
            tail = node;
        }
    }

    void evictLRU() {
        if (tail) {
            cacheMap.erase(tail->key);
            if (tail->prev) {
                tail->prev->next = nullptr;
            } else {
                head = nullptr;
            }
            Node* temp = tail;
            tail = tail->prev;
            delete temp;
        }
    }
};
