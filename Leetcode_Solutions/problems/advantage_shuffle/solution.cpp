class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        map<int, int> hash;
        for(auto it:A){
            hash[it]++;
        }
        vector<int> ans;
        for(int i=0;i<B.size();i++){
            map<int,int>::iterator it;
            if(hash.size())
                it = hash.upper_bound(B[i]);
            if(hash.size() && it!=hash.end()){
                ans.push_back(it->first);
                if(it->second==1)
                    hash.erase(it->first);
                else
                    hash[it->first]--;
            }
            else ans.push_back(-1);
            //cout<<B[i]<<' '<<ans[i]<<endl;
        }
        auto it = hash.begin();
        for(int i=0;i<ans.size();i++){
            if(ans[i]==-1 && hash.size()>0){
                auto it = hash.begin();
                ans[i]=it->first;
                hash[it->first]--;
                if(hash[it->first]==0)hash.erase(it->first);
            }
        }
        return ans;
    }
};