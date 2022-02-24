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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode(),*temp=ans;
        int rem = 0;
        while(l1 && l2){
            int curr = l1->val+l2->val+rem;
            rem = curr/10;
            curr%=10;
            temp->next = new ListNode(curr);
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int curr = l1->val+rem;
            rem = curr/10;
            curr%=10;
            temp->next = new ListNode(curr);
            l1=l1->next;
            temp=temp->next;
        }
        while(l2){
            int curr = l2->val+rem;
            rem = curr/10;
            curr%=10;
            temp->next = new ListNode(curr);
            l2=l2->next;
            temp=temp->next;
        }
        if(rem){
            temp->next = new ListNode(1);
        }
        return ans->next;
    }
};