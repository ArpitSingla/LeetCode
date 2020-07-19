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
    ListNode *reverseLL(ListNode *head){
        if(head==NULL){
            return head;
        }
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *fwd=NULL;
        while(curr!=NULL){
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode *start=head;
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *revStart=reverseLL(slow->next);
        ListNode *temp1=NULL,*temp2=NULL;
        while(start!=NULL && revStart!=NULL){
            temp1=start->next;
            temp2=revStart->next;
            start->next=revStart;
            start=temp1;
            revStart->next=start;
            revStart=temp2;
        }
        if(start!= NULL){
            start->next = NULL;
        }
    }
};