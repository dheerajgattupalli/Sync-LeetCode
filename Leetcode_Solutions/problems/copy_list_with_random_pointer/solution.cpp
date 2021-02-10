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
        if(!head)return head;
        unordered_map<Node *,Node *> pointer_map;
        Node *copy = NULL, *ans = NULL,*head_copy = head;
        while(head){
            if(!copy){
                copy = new Node(head->val);
                ans = copy;
            }
            else{
                copy->next = new Node(head->val);
                copy = copy->next;
            }
            pointer_map[head] = copy;
            head = head->next;
        }
        copy = ans;
        head = head_copy;
        while(head){
            //cout<<head->random<<' '<<pointer_map[head->random]<<endl;
            copy->random = pointer_map[head->random];
            head = head->next;
            copy = copy->next;
        }
        return ans;
    }
};