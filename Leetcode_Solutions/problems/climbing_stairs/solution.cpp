class Solution {
public:
    vector<int> dp;
    Solution(){
        dp.clear();
        for(int i=0;i<46;i++){
            dp.push_back(-1);
        }
    }
    int climbStairs(int n) {
        if(n<=2)return max(n,0);
        if(dp[n]!=-1)return dp[n];
        dp[n] = climbStairs(n-1)+climbStairs(n-2); 
        return dp[n];
    }
};