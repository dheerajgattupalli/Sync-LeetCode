class compareFn{
public:
    bool operator() (const int &a,const int &b)const {return a>b;}
};
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int,compareFn> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        vector<pair<int,int>> data(hash.size());
        vector<int> dp(hash.size()+1,0);
        int i=0;
        for(auto x:hash){
            data[i++]=x;
        }
        for(int i=0;i<data.size();i++){
            if(i>0 && data[i].first==data[i-1].first-1){
                //cout<<"prev "<<dp[i]<<endl;
                dp[i+1] = max(dp[i], dp[i-1]+data[i].first*data[i].second);
            }
            else{
                dp[i+1] = dp[i]+data[i].first*data[i].second;
            }
            //cout<<dp[i+1]<<endl;
        }
        return dp[hash.size()];
    }
};