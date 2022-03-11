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
        ListNode *next1=head,*next2=head,*ans;
        int count=0;
        while(next1){
            next1=next1->next;
            count++;
        }
        if(count==0)return head;
        k=k%count;
        count=0;
        next1=head;
        if(k==0)return head;
        while(next2->next){
            next2=next2->next;
            if(count>=k){
                next1=next1->next;
                //if(count==k)ans=head;
            }
            count++;
        }
        ans=next1->next;
        next1->next=NULL;
        next2->next=head;
        return ans;
    }
};