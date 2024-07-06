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
public:
    ListNode* Merge(ListNode* a , ListNode* b){
        ListNode* res ;
        if(a == nullptr)
            return b;
        if(b == nullptr)
            return a;
        if(a->val <= b->val){
            res=a;
            res->next = Merge(a->next , b);
        }else{
            res=b;
            res->next = Merge(a , b->next);
        }
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
        for(int i = 1 ; i < lists.size() ; ++i){
            lists[0] = Merge(lists[0],lists[i]);
        }
        return lists[0];
    }
};