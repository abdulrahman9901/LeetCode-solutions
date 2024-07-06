// https://leetcode.com/problems/remove-nodes-from-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev = head;
        ListNode* current = head->next;
        while(current != nullptr){
             if(current->val > head->val){
                    head = current;
            }
            if(current->val > prev->val){
                head->next = current;
            }
            current = current->next; 
            prev = prev->next; 
        }
        return head;
    }
};