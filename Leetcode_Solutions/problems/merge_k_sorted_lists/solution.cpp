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
    bool comparing(pair<int,int> a, pair<int,int> b){
        return a.first>b.first;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<lists.size();i++){
            if(lists[i])q.push(make_pair(lists[i]->val,i));
        }
        ListNode *temp=NULL,*ans=NULL;
        while(!q.empty()){
            pair<int,int> t = q.top();
            q.pop();
            if(!ans){
                ans = new ListNode(t.first);
                temp = ans;
                lists[t.second] = lists[t.second]->next;
                if(lists[t.second]){
                    q.push(make_pair(lists[t.second]->val,t.second));
                }
            }
            else{
                temp->next = new ListNode(t.first);
                temp = temp->next;
                lists[t.second] = lists[t.second]->next;
                if(lists[t.second])
                    q.push(make_pair(lists[t.second]->val,t.second));
            }
        }
        return ans;
    }
};