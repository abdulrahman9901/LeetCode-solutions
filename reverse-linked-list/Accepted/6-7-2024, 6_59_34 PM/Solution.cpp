// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        stack<int> vals;
        while(current){
            vals.push(current->val);
            current=current->next;
        }
        current = head;
        while(current){
            current->val = vals.top();
            vals.pop();
            current=current->next;
        }
        return head;
    }
};