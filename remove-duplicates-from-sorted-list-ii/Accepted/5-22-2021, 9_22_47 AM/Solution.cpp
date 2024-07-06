// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
    int arr[201];
    void initalize(){
        for(int i=0;i<201;++i)
            arr[i]=0;
    }
    void cleanUp(ListNode*& head,int k){
        ListNode* current=head,*prev=nullptr,*temp;
        while(current!=nullptr){
             temp=current;
            if(arr[(current->val)+100] > k){
                arr[(current->val)+100]++;
                current=current->next;
                if(prev)
                    prev->next=temp->next;
                else{
                    head=current;
                }
                temp->next=nullptr;
                delete temp;
            }else if(arr[(current->val)+100]==k){
                current=current->next;
                prev=temp;
                arr[(temp->val)+100]++;
            }       
         }
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        initalize();
         cleanUp(head,0);
         cleanUp(head,1);
        return head;
    }
};