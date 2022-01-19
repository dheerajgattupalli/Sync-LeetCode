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
        ListNode *slow=head,*fast=head;
        bool cycle = false;
        while(fast && slow){
            slow=slow->next;
            fast=fast->next;
            if(fast)fast=fast->next;
            if(fast==slow && fast){
                cycle=true;
                break;
            }
        }
        if(cycle){
            slow=head,fast=head;
            while(1){
                slow=slow->next;
                fast=fast->next;
                if(fast)fast=fast->next;
                if(slow==fast)break;
            }
            //cout<<slow->val<<endl;
            ListNode *ans=head;
            while(ans!=slow){
                ans=ans->next;
                slow=slow->next;
                //if(slow)slow=slow->next;
            }
            return ans;
        }
        return nullptr;
    }
};