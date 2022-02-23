/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        Node *ans;
        queue<Node *> q;
        q.push(node);
        ans = new Node(node->val);
        Node* temp = ans;
        unordered_map<int, Node*> visited;
        visited[ans->val] = ans;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node *curr = q.front();
                q.pop();
                vector<Node*> neighs = curr->neighbors;
                if(visited.find(curr->val)!=visited.end())
                    temp = visited[curr->val];
                for(int i=0;i<neighs.size();i++){
                    if(visited.find(neighs[i]->val)==visited.end()){
                        q.push(neighs[i]);
                        visited[neighs[i]->val] = new Node(neighs[i]->val);   
                    }
                    temp->neighbors.push_back(visited[neighs[i]->val]);
                }
            }
        }
        return ans;
    }
};