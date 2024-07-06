// https://leetcode.com/problems/remove-nodes-from-linked-list

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
    ListNode* removeNodes(ListNode* head) {
        ListNode* current = head,*node;
        stack<ListNode*> st;
        while(current != nullptr){
            while(!st.empty() && st.top()->val < current->val){
                st.pop();
            }
            st.push(current);
            current = current->next; 
        }
        head = nullptr;
        while(!st.empty()){
            node = st.top(); 
            st.pop();
            node->next = head;
            head = node;
        }
        return head;
    }
};