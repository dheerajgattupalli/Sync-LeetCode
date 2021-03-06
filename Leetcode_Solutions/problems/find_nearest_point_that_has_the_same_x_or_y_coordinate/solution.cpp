class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        float min_dist = INT_MAX;
        for(int i=0;i<points.size();i++){
            if(x==points[i][0] || y==points[i][1]){
                int diff_x = x-points[i][0];
                int diff_y = y-points[i][1];
                float dist = sqrt(diff_x*diff_x+diff_y*diff_y);
                //cout<<i<<' '<<dist<<endl;
                if(dist<min_dist){
                    ans = i;
                    min_dist = dist;
                }
            }
        }
        return ans;
    }
};