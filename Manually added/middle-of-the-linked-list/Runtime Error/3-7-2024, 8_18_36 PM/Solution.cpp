// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        int count ; float middle;
        if(head->next == nullptr){
            return head;
        }
        ListNode* current = head;
        while(current->next){
            current=current->next;
        }
        count = current->val;
        current = head;
        middle = floor(count/2.0);
        while(middle--){
            current=current->next;
        }
        return current;
    }
};