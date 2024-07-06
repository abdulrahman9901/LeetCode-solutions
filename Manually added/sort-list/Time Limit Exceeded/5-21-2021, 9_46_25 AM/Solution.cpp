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
   deque<int>dq ;
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr)
            return head;
        ListNode *current=head->next;
        dq.push_back(head->val);
        while(current!=nullptr){
            if(current->val <= dq.front())
                dq.push_front(current->val);
            else if(current->val >= dq.back())
                dq.push_back(current->val);
            else{
                int c=0;
                while(current->val < dq.back()){
                    dq.push_front(dq.back());
                    dq.pop_back();
                    c++;
                }dq.push_back(current->val);
                while(c--){
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }
            current=current->next;
        }
       current=head;
        while(current!=nullptr){
            current->val=dq.front();
             dq.pop_front();
            current=current->next;
        } return head;
    }
};