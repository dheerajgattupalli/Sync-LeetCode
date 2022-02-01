class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,n = prices.size(),min_val = prices[0];
        for(int i=1;i<n;i++){
            if(ans<(prices[i]-min_val))ans = prices[i]-min_val;
            if(min_val>prices[i])min_val = prices[i];
        }
        return ans;
    }
};