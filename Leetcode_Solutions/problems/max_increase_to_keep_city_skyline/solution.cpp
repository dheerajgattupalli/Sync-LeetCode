class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row_max(grid.size(),-1),col_max(grid[0].size(),-1);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                //cout<<i<<' '<<j<<endl;
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                //cout<<i<<' '<<j<<' '<<min(row_max[i],col_max[i])<<endl;
                ans+= max(0, min(row_max[i],col_max[j])-grid[i][j]);
            }
        }
        return ans;
    }
};