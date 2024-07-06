// https://leetcode.com/problems/rotate-list

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
  
    ListNode* rotateRight(ListNode* head, int k) {
          if(k==0 || head==nullptr ||head->next==nullptr)
            return head;
        ListNode* current=head,*end;
        while(current->next->next!=nullptr){
           current=current->next;
        }end=current->next;
        end->next=head;
        current->next=nullptr;
        head=end;
        return rotateRight(head,k-1);
    }
};