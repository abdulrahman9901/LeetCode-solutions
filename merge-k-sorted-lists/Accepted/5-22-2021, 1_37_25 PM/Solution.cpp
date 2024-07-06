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
        if(lists.size()==0)
            return nullptr;
        // ListNode* temp=lists[0];
        for(int i=1;i<lists.size();++i){
            lists[0]=merge(lists[0],lists[i]);
        }
        return lists[0];
    }
};