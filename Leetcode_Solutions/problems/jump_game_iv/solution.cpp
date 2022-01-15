class Solution {
public:
    void recFun(vector<int>& arr, int x, int curr, map<int, vector<int>> &jumps, vector<int> &dp,int limit){
        cout<<x<<endl;
        if(x<0 || x>limit || (dp[x]>0 && curr>dp[x]))return;
        //if(x==limit){
        //    dp[x]=min(dp[x],curr);
        //    return;
        //}
        if(dp[x]==-1)dp[x]=curr;
        else dp[x] = min(curr, dp[x]);
        if(jumps.find(arr[x])!=jumps.end())
            for(auto y:jumps[arr[x]]){
                if(y>x)recFun(arr, y, curr+1, jumps, dp, limit);
        }
        recFun(arr, x-1, curr+1, jumps, dp, limit);
        recFun(arr, x+1, curr+1, jumps, dp, limit);
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,n);
        map<int,vector<int>> jumps;
        for(int i=n-1;i>=0;i--){
            if(jumps.find(arr[i])==jumps.end()){
                vector<int> t(1,i);
                jumps[arr[i]]=t;
            }
            else jumps[arr[i]].push_back(i);
        }
        //recFun(arr, 0, 0, jumps, dp, n-1);
        queue<int> q1;
        int size = 0, depth = 0;
        q1.push(0);
        while(!q1.empty()){
            size = q1.size();
            //cout<<q1.size()<<endl;
            while(size--){
                //if(depth>0)cout<<n<<" Inside "<<size<<endl;
                int x = q1.front();
                q1.pop();
                dp[x] = min(depth, dp[x]);
                for(auto y:jumps[arr[x]]){
                    if(y!=x && dp[y]>(dp[x]+1)){
                        //if(depth>0)cout<<y<<' '<<dp[y]<<endl;
                        dp[y] = min(dp[x]+1, dp[y]);
                        q1.push(y);
                       if(y==n-1)return dp[y];
                    }
                }
                jumps[arr[x]].clear();
                if(x+1<n && arr[x+1]!=arr[x] && (dp[x]+1)<dp[x+1]){
                    dp[x+1]=dp[x]+1;
                    q1.push(x+1);
                    if(x+1==n-1)return dp[x+1];
                }
                if(x-1>=0 && arr[x-1]!=arr[x] && (dp[x]+1)<dp[x-1]){
                    dp[x-1]=dp[x]+1;
                    q1.push(x-1);
                }
            }
            depth++;
        }
        return dp[n-1];
    }
};