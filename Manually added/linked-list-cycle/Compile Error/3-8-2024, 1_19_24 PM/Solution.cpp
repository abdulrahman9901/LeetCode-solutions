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
        if(visisted.contains(current)){
            return true;
        }else {
            visisted[current] = true;
            
        }
    }
};