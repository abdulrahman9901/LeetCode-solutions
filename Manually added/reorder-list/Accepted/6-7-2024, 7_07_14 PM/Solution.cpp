// https://leetcode.com/problems/reorder-list

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
    void reorderList(ListNode* head) {
        ListNode* current = head;
        vector<int> vals;
        while(current){
            vals.push_back(current->val);
            current = current->next;
        }
        current = head;
        int n = vals.size() - 1, i = 0;
        while(current){
            current->val = vals[i];
            current = current->next;
            if(current)
            {
                current->val = vals[n-i];
                current = current->next;
            }
            i++;
        }    
    }
};