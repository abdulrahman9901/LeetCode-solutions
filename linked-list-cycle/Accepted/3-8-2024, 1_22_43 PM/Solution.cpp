// https://leetcode.com/problems/linked-list-cycle

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
    bool hasCycle(ListNode *head) {
        ListNode * current = head;
        map<ListNode * , bool> visisted ;
        if(head == nullptr || head->next == nullptr )
            return false ;
        while(current->next){
            if(visisted.contains(current)){
                return true;
            }else {
                visisted[current] = true;
                current = current->next;
            }
        }
        return false;
    }
};