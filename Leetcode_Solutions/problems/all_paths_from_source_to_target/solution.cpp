class Solution {

public:
    void recurFun(vector<vector<int>> &graph, vector<vector<int>> &paths,
                 int x,vector<int>& curr_path){
        //for(auto k:curr_path)cout<<k<<' ';
        //cout<<endl;
        //curr_path.push_back(x);
        if(x==graph.size()-1){
            paths.push_back(curr_path);
        }
        //for(int i=x;i<graph.size();i++){
        for(int j=0;j<graph[x].size();j++){
            curr_path.push_back(graph[x][j]);
            recurFun(graph,paths,graph[x][j],curr_path);    
            curr_path.pop_back();
        }
        //}
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp(1,0);
        recurFun(graph,ans,0,temp);
        return ans;
    }
};