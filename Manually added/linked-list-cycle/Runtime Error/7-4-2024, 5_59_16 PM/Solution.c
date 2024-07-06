// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode * slow=head , *fast=head;
    if(head == NULL || head->next == NULL)
        return false;
    while(fast->next){
        slow = slow->next;
        fast=fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}