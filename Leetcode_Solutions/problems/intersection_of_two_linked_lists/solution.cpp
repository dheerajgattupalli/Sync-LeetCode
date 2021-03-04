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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = headA,*temp1=NULL,*temp2=NULL;
        int l1 = 0,l2=0;
        while(temp){
            l1++;
            temp = temp->next;
        }
        //cout<<"Here"<<endl;
        temp = headB;
        while(temp){
            l2++;
            temp = temp->next;
        }
        //cout<<"Here2"<<endl;
        if(l1>l2){
            temp1 = headA;
            temp2 = headB;
            int n = l1-l2;
            while(n-- && temp1)temp1=temp1->next;
        }
        else{
            temp1 = headA;
            temp2 = headB;
            int n = l2 - l1;
            while(n-- && temp2)temp2 = temp2->next;
        }
        //cout<<"Not Here"<<endl;
        //cout<<temp1->val<<' '<<temp2->val<<endl;
        while(temp1 && temp2 && temp1!=temp2){
            temp1  = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};