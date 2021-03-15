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
    int getLen(ListNode* head){
        int n = 0;
        while(head){
            head = head->next;
            n++;
        }
        return n;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n = getLen(head);
        ListNode*a=NULL, *b=NULL, *start = head;
        int curr=1;
        while(start){
            if(curr==k)a=start;
            if(curr==n-k+1)b=start;
            curr++;
            start=start->next;
        }
        int temp=a->val;
        a->val = b->val;
        b->val = temp;
        return head;
    }
};