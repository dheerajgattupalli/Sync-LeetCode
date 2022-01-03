class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1)return 1;
        map<int, int> hash1,hash2;
        for(int i=0;i<trust.size();i++){
            hash1[trust[i][0]]++;
            if(hash1.find(trust[i][1])==hash1.end())hash1[trust[i][1]] = 0;
            if(hash2.find(trust[i][0])==hash2.end())hash2[trust[i][0]] = 0;
            hash2[trust[i][1]]++;
        }
        for(auto x:hash1){
            //cout<<x.first<<' '<<x.second<<' '<<hash2[x.first]<<endl;
            if(x.second==0 && hash2[x.first]==hash1.size()-1)return x.first;
        }
        return -1;
    }
};