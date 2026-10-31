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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int len=1;
        ListNode* temp=head;
        while(temp->next!=0){
        len++;
        temp=temp->next;
        }
        k=k%len;
        ListNode* now=head;
        int cnt=0;
        while(now!=NULL){
            cnt++;
            if(cnt==len-k){
                break;
            }
            now=now->next;
        }
        temp->next=head;
        head=now->next;
        now->next=NULL;
        return head;
    }
};