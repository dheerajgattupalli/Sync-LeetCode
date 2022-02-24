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
    ListNode *mergeFun(ListNode *first, ListNode* second){
        if(!first)return second;
        if(!second)return first;
        //cout<<first->val<<' '<<second->val<<endl;
        ListNode* merged;
        if(first->val<second->val){
            merged = first;//new ListNode(first->val);
            first = first->next;
        }
        else {
            merged = second;
            second=second->next;
        }
        ListNode* returnNode = merged;
        while(first && second){
            if(first->val<second->val){
                merged->next = first;
                merged=merged->next;
                first = first->next;
            }
            else{
                merged->next = second;
                merged=merged->next;
                second = second->next;
            }
        }
        if(first){
            merged->next = first;
        }
        if(second){
            merged->next = second;
        }
        return returnNode;
    }
    ListNode *recFun(ListNode *start){
        if(!start || !start->next)return start;
        ListNode *slow=start,*fast=start,*parent=NULL;
        while(slow && fast){
            parent = slow;
            slow=slow->next;
            fast=fast->next;
            if(fast)fast=fast->next;
        }
        parent->next = NULL;
        start = recFun(start);
        slow  = recFun(slow);
        ListNode *merged = mergeFun(start, slow);
        return merged;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* ans = recFun(head);
        return ans;
    }
};