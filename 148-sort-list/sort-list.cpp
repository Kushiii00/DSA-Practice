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
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* t1=left;
        ListNode* t2=right;
        ListNode* dNode=new ListNode(-1);
        ListNode* temp=dNode;
        while(t1!=NULL && t2!=NULL){
            if(t1->val<=t2->val){
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        temp->next = (t1 != NULL) ? t1 : t2;
        return dNode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=middle(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
       left=sortList(left);
       right=sortList(right);
     return  merge(left,right);
  
    }
};