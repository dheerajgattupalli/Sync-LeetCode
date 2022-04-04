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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp=new ListNode(),*kth,*nkth;
        temp->next = head;
        int c=0;
        ListNode *ans=temp;
        while(temp){
            if(c==k){
                kth=temp;
            }
            else if(c==k){
                nkth=head;
            }
            else if(c>k){
                nkth=nkth->next;
            }
            temp=temp->next;
            c++;
        }
        cout<<kth->val<<' '<<nkth->val<<endl;
        //ListNode *t1=kth->next,*t2=kth->next->next,*t3=nkth->next->next;
        //kth->next = nkth->next;
        //kth->next->next = t2;
        //nkth->next = t1;
        //nkth->next->next = t3;
        int temper = kth->val;
        kth->val = nkth->val;
        nkth->val = temper;
        return ans->next;
    }
};