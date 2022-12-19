class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)return true;
        queue<int> q1;
        unordered_map<int, vector<int>> adj_matrix;
        for(auto x:edges){
            adj_matrix[x[0]].push_back(x[1]);
            adj_matrix[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n,false);
        visited[source]=true;
        q1.push(source);
        int curr;
        while(!q1.empty()){
            queue<int> q2;
            while(!q1.empty()){
                curr = q1.front();
                visited[curr]=true;
                q1.pop();
                for(int i=0;i<adj_matrix[curr].size();i++){
                    if(adj_matrix[curr][i]==destination)return true;
                    if(!visited[adj_matrix[curr][i]])
                        q2.push(adj_matrix[curr][i]);
                }
            }
            q1=q2;
        }
        return false;
    }
};