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
    ListNode *reverse(ListNode *head){
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *fwd=head;
        while(curr!=NULL){
            fwd=fwd->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return true;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *prev=NULL;
        ListNode *first=head;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL){
            slow=slow->next;
        }
        ListNode *temp=reverse(slow);
        prev->next=temp;
        ListNode *second=temp;
        while(second!=NULL){
            if(first->val != second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;
    }
};