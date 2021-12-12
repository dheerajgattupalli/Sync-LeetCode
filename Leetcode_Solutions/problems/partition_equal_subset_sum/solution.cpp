class Solution {
public:
    bool recurFn(vector<int> &nums,vector<int> &dp, int x, int s1,int s2){
        if(s1==s2)return true;
        int n = nums.size();
        if(x>=n)return false;
        if(s1>s2 ||dp[s1]==0)return false;
        bool ans = false;
        for(int i=x;i<n;i++){
            ans|=recurFn(nums,dp, i+1, s1+nums[i], s2-nums[i]);
        }
        dp[s1] = (int)ans;
        //dp[s2] = (int)ans;
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        //sort(nums.begin(),nums.end(),less<int>());
        for(auto x:nums)total+=x;
        if(total%2)return false;
        vector<int> dp(total+1,-1);
        //int s1 = 0,s2=total;
        //for(int i=0,j=n-1;i<=j;){
        //    if(s1<)
        //}
        return recurFn(nums,dp, 0, 0, total);
    }
};