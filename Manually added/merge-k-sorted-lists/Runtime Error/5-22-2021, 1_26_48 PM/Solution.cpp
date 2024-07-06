// https://leetcode.com/problems/merge-k-sorted-lists

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
     ListNode* merge(ListNode* a,  ListNode*b ){
          ListNode* res;
        if(a==nullptr)
            return b;
        else if(b==nullptr)
            return a;
        if(a->val <= b->val){
            res=a;
            res->next=merge(a->next,b);
        }else{
            res=b;
            res->next=merge(a,b->next);
        }
         return res;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         ListNode* temp=lists[0];
        for(int i=1;i<lists.size();++i){
            temp=merge(temp,lists[i]);
        }
        return temp;
    }
};