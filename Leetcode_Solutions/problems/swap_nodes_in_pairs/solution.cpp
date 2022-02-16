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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *first=head,*second,*ans,*prev=NULL;
        while(first){
            //cout<<first->val<<endl;
            second=first->next;
            if(second)first->next=second->next;
            if(second)second->next=first;
            if(first==head)ans=second;
            if(prev && second)prev->next=second;
            prev=first;
            first=first->next;
        }
        return ans;
    }
};