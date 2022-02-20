class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans = 0,n = intervals.size(),x1=-1,x2=-1;
        for(int i=0;i<n;i++){
            if(intervals[i][1]>x2 &&
              intervals[i][0]>x1){
                ans++;
            }
            if(intervals[i][1]>x2){
                x1 = intervals[i][0];
                x2 = intervals[i][1];
            }
        }
        return ans;
    }
};