/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool ok=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ok=true;
                break;
            }
        }
        if(ok==true){
            slow=head;
            while(fast!=NULL && fast->next!=NULL){
                if(slow==fast) return slow;
                slow=slow->next;
                fast=fast->next;
                
            }
        }
        return NULL;
    }
};