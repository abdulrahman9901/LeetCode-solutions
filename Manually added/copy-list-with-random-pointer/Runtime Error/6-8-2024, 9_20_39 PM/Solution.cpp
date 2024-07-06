// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newList = new Node(head->val);
        map<Node* , Node* > addressMap;
        Node* oldCurrent = head->next , *newCurrent = newList;
        addressMap[head] = newList;
        while(oldCurrent){
            newCurrent->next = new Node(oldCurrent->val);
            addressMap[oldCurrent] = newCurrent->next;
            oldCurrent = oldCurrent->next;
            newCurrent = newCurrent->next;
        }
        oldCurrent = head ; newCurrent = newList;
        while(oldCurrent){
            newCurrent->random = addressMap[oldCurrent->random];
            oldCurrent = oldCurrent->next;
            newCurrent = newCurrent->next;
        }
        return newList;
    }
};