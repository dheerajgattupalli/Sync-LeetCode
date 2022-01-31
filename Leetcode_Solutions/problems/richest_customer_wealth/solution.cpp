class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0, curr=0, n = accounts.size(), m = accounts[0].size();
        for(int i=0;i<n;i++){
            curr = 0;
            for(int j=0;j<m;j++){
                curr+=accounts[i][j];
            }
            if(curr>ans)
                ans = curr;
        }
        return ans;
    }
};