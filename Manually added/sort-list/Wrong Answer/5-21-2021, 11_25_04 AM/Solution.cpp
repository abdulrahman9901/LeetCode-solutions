// https://leetcode.com/problems/sort-list

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
    ListNode* newhead;
    void merge(ListNode* start, ListNode* end) {
        if (start == nullptr || start == end)
            return;
        ListNode* current = start->next, * prev = start, * oldhead = start;
        while (current != end) {
            if (current->val < oldhead->val) {
                prev->next = current->next;
                current->next = start;
                start = current;
                current = oldhead;
                newhead = start;
            }
            prev = current;
            current = current->next;
        }
        merge(start, oldhead);
        merge(oldhead->next,end);
    }
public:
    ListNode* sortList(ListNode* head) {
        merge(head, nullptr);
        return newhead;
    }
};