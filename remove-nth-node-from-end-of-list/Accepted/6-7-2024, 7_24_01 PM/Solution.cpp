// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        vector<int> vals;
        while(current){
            vals.push_back(current->val);
            current = current->next;
        }
        int pos = vals.size() - n;
        cout<<pos<<endl;
        if(n == vals.size()){
            return head->next;
        }
        current = head;
        while(current->next){
            if(pos != 1){
                current = current->next;
                pos--;
                }
            else 
                break;
        }
        current->next = current->next ?current->next->next :nullptr  ;
        return head;
    }
};