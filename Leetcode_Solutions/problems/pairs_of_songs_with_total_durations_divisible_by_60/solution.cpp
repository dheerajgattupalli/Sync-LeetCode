class Solution {
public:
    int nc2(int n){
        return (n*(n-1))/2;
    }
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        map<int,int> hash;
        for(int i=0;i<n;i++)hash[time[i]%60]++;
        int ans=0;
        for(auto x:hash){
            //cout<<x.first<<' '<<x.second<<endl;
            if(x.first<30){
                auto y = hash.find(60-x.first);
                if(y!=hash.end()){
                    ans+=(x.second*y->second);
                }
            }
        }
        //cout<<"final"<<ans<<' '<<nc2(hash[0])<<' '<<nc2(hash[30])<<endl;
        return ans+nc2(hash[0])+nc2(hash[30]);
    }
};