// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addNode(ListNode* cur,int val){
            cur->next=new ListNode(val);
        return (cur->next);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto cur1=l1,cur2=l2;
        int cry=0;
        int sum=cur1->val+cur2->val+cry;
        cry=sum/10;
        sum=sum%10;
        ListNode* res=new ListNode(sum);
        auto cur=res;
            while(cur1->next!=nullptr && cur2->next!=nullptr){
                cur1=cur1->next;
                cur2=cur2->next;
                sum=cur1->val+cur2->val+cry;
                cry=sum/10;
                sum=sum%10;
                cur=addNode(cur,sum);
                
          } if(cur1->next==nullptr){
                while(cur2->next!=nullptr){
                cur2=cur2->next;
                sum=cur2->val+cry;
                cry=sum/10;
                sum=sum%10;
                cur=addNode(cur,sum);
                }
            }else{
                while(cur1->next!=nullptr){
                cur1=cur1->next;
                sum=cur1->val+cry;
                cry=sum/10;
                sum=sum%10;
                cur=addNode(cur,sum);
                }
            }
        return res;
    }
};