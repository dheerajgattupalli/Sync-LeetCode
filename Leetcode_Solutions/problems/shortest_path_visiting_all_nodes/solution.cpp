class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==1)return 0;
        int endMask = (1<<n)-1;
        vector<vector<bool>> seen(n,vector<bool>(endMask));
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            vector<int> temp;
            temp.push_back(i);
            temp.push_back(1<<i);
            q.push(temp);
            seen[i][1<<i]=true;
        }
        int steps = 0;
        while(!q.empty()){
            int qsize=q.size();
            queue<vector<int>> q2;
            while(qsize--){
                vector<int> curr = q.front();
                q.pop();
                int node = curr[0];
                int mask = curr[1];
                for(auto x:graph[node]){
                    int nextMask = mask  | (1<<x);
                    if(nextMask==endMask)return 1+steps;
                    if(!seen[x][nextMask]){
                        seen[x][nextMask]=true;
                        vector<int> temp;
                        temp.push_back(x);
                        temp.push_back(nextMask);
                        q2.push(temp);
                    }
                }
            }
            steps++;
            q = q2;
        }
        return -1;
    }
};