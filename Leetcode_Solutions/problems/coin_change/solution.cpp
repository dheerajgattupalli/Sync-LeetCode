class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<coins.size();j++){
                if(i==0)dp[i]=0;
                else if(i>=coins[j]){
                    //cout<<i<<' '<<coins[j]<<endl;
                    if(dp[i]==-1 && dp[i-coins[j]]!=-1)dp[i] = dp[i-coins[j]]+1;
                    else if(dp[i-coins[j]]!=-1)dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
           // cout<<i<<' '<<dp[i]<<endl;
        }
        return dp[amount];
    }
};