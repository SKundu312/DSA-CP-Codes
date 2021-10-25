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
/////////////////////////////////////////////////////Leetcode////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL,*nex=NULL;
        while(curr!=NULL){
            nex = curr->next;
           curr->next=prev;
            prev=curr;
            curr=nex;
            
        }
        head=prev;
        return head;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* rev=reverseList(head);
        int s=0,i=0;
        while(rev!=NULL){
            s+=(rev->val)*pow(2,i);
            i++;
            rev=rev->next;
        }
        return s;
    }
};
