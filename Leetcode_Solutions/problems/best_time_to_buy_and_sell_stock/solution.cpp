class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = prices[0], n=prices.size(), ans = 0;
        for(int i=0;i<n;i++){
            if((prices[i]-currMin)>ans)
                ans = prices[i]-currMin;
            if(currMin>prices[i])
                currMin = prices[i];
        }
        return ans;
    }
};