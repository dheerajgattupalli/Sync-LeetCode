/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node *> level;
        level.push(root);
        while(!level.empty()){
            int size = level.size();
            Node *prev = NULL;
            while(size--){
                Node *curr = level.front();
                //cout<<curr->val<<' ';
                level.pop();
                if(prev)prev->next=curr;
                prev = curr;
                if(curr->left)level.push(curr->left);
                if(curr->right)level.push(curr->right);
            }
            cout<<endl;
        }
        return root;
    }
};