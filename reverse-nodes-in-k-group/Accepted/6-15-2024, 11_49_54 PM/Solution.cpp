// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> groups;
        ListNode* current = head , *groupSt = head;
        int size = 0;
        while(current){
            size++;
            groups.push_back(current);
            if(size == k){
               for(int i = 0 ; i <  k/2 ; ++i){
                int temp = groups[i]->val;
                groups[i]->val = groups[k-1-i]->val;
                groups[-i+k-1]->val = temp;
               }
               groups.erase(groups.begin(), groups.end());  
               size = 0;
            }
            current = current->next;
        }
        return head;
    }
};