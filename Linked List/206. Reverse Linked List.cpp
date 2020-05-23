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
    ListNode* reverseList(ListNode* head) {    //recursive solution
        if(head==NULL ||head->next==NULL){
            return head;
        }
        ListNode *temp=reverseList(head->next);
        ListNode *vari=temp;
        while(vari->next!=NULL){
            vari=vari->next;
        }
        vari->next=head;
        head->next=NULL;
        return temp;
    }

    ListNode* reverseList(ListNode* head) {   //Iterative Solution
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *fwd=head;
        while(curr!=NULL){
            fwd=fwd->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
        }
        return prev;
    }
};