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
     void split(ListNode* head,ListNode*& a, ListNode*& b) {
         ListNode* first = head->next, * slow = head;
         while (first != nullptr) {
             first = first->next;
             if (first != nullptr) {
                 first = first->next;
                 slow = slow->next;
             }
         }
         a = head;
         b = slow->next;
         slow->next = nullptr;
     }
     ListNode* merge(ListNode* a, ListNode* b) {
         ListNode* res;
         if (a == nullptr)
             return b;
         else if (b == nullptr)
             return a;
         if (a->val <= b->val) {
             res = a;
             res->next = merge(a->next, b);
         }
         else {
             res = b;
             res->next = merge(a, b->next);
         }
         return res;
     }
    void sort(ListNode* &head) {
         ListNode* a, * b;
         if (head == nullptr || head->next == nullptr)
             return;
          split(head,a, b);
            
          sort(a);
          sort(b);
          head = merge(a, b);
     }
 public:
     ListNode* sortList(ListNode* head) {
         sort(head);
         return head;
     }
 };