class Solution {
public:
    int recurShortestPath(vector<vector<int>> grid, vector<vector<int>> &min_paths){
        vector<vector<int>> neighbours{{1,1},{1,-1}, {-1,1}, {-1,-1}, {1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> possible_path;
        possible_path.push(make_pair(0,0));
        while(!possible_path.empty()){
            auto curr_vertex = possible_path.front();
            possible_path.pop();
            int x= curr_vertex.first;
            int y = curr_vertex.second;
            for(int i=0;i<8;i++){
                if(x+neighbours[i][0]>=0 && x+neighbours[i][0]<grid.size() &&
                y+neighbours[i][1]>=0 && y+neighbours[i][1]<grid[0].size() &&
                  min_paths[x][y]+1<min_paths[x+neighbours[i][0]][y+neighbours[i][1]] &&
                  grid[x+neighbours[i][0]][y+neighbours[i][1]]!=1){
                    //cout<<'('<<x+neighbours[i][0]<<','<<y+neighbours[i][1]<<')'<<' ';
                    min_paths[x+neighbours[i][0]][y+neighbours[i][1]] = min_paths[x][y]+1;
                    possible_path.push(make_pair(x+neighbours[i][0],y+neighbours[i][1]));
                }
            }
            //cout<<endl;
        }
        return min_paths[grid.size()-1][grid[0].size()-1];
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        vector<vector<int>> min_paths(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        if(grid[0][0])return -1;
        min_paths[0][0]=1;
        ans = recurShortestPath(grid, min_paths);
        if(ans==INT_MAX)return -1;
        return ans;
    }
};