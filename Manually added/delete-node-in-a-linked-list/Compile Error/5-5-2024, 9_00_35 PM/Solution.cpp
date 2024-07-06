// https://leetcode.com/problems/delete-node-in-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* current=node->next , prev=node; 
        while(current->next != nullptr){
            prev->val = current->val ;
            current = current->next;
            prev = prev->next;
        }
        prev->val = current->val ;
        
    }
};