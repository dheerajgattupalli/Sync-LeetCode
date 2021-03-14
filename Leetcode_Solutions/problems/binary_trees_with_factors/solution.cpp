class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<long long, long long> ans;
        long long mod = 1000000007;
        vector<long long> arr2(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            ans[arr2[i]]=1;
        }
        sort(arr2.begin(),arr2.end());
        int fin_ans = 0;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<=i;j++){
                long long curr = arr2[i]*arr2[j];
                if(curr>mod)continue;
                if(ans.find(curr)!=ans.end()){
                    ans[curr] = ans[curr]%mod + (ans[arr2[i]]%mod*ans[arr2[j]]%mod)%mod;
                    if(arr2[i]!=arr2[j]){
                        ans[curr]= ans[curr]%mod + (ans[arr2[i]]%mod*ans[arr2[j]]%mod)%mod;
                        
                    }
                    //cout<<curr<<' '<<ans[curr]<<' '<<arr2[i]<<' '<<arr2[j]<<endl;
                }
            }
        }
        for(auto x:ans){
            fin_ans= (fin_ans%mod + x.second%mod)%mod;
        }
        return fin_ans;
    }
};