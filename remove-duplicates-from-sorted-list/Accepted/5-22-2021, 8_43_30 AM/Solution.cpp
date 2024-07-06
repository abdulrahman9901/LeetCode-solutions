// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        initalize();
         ListNode* current=head,*prev=head;
        while(current!=nullptr){
            auto temp=current;
            if(arr[(current->val)+100]!=0){
                current=current->next;
                prev->next=temp->next;
                temp->next=nullptr;
                delete temp;
            }else{
                current=current->next;
                prev=temp;
                arr[(temp->val)+100]++;
            }
        }return head;
    }
};