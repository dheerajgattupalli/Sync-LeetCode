/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *,Node *> hash;
        Node *save = head;
        int index = 0;
        Node *ans=new Node(-1);
        Node *temp = ans,*prev=NULL;
        while(head){
            ans->next = new Node(head->val);
            hash[head] = ans->next;
            if(prev)prev->next = ans->next;
            head = head->next;
            ans = ans->next;
        }
        head = save;
        ans = temp;
        while(head){
            ans->next->random = hash[head->random];
            head = head->next;
            ans = ans->next;
        }
        return temp->next;
    }
};