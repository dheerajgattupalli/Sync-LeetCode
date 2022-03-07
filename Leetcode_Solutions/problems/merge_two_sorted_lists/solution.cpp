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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;
        ListNode *ans=NULL,*temp=NULL;
        while(list1 && list2){
            if(list1->val<list2->val){
                if(!temp)temp = new ListNode(list1->val);
                else{
                    temp->next = new ListNode(list1->val);
                    temp = temp->next;
                }
                list1=list1->next;
            }
            else{
                if(!temp)temp = new ListNode(list2->val);
                else{
                    temp->next = new ListNode(list2->val);
                    temp = temp->next;
                }
                list2=list2->next;
            }
            if(ans==NULL)ans=temp;
        }
        while(list1){
            temp->next = new ListNode(list1->val);
            temp = temp->next;
            list1=list1->next;
        }
        while(list2){
            temp->next = new ListNode(list2->val);
            temp = temp->next;
            list2=list2->next;
        }
        return ans;
    }
};