class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash1(26,0);
        int k = p.size();
        for(int i=0;i<k;i++){
            hash1[p[i]-'a']++;
        }
        //cout<<hash1[0]<<' '<<k<<endl;
        vector<int>curr=hash1;
        vector<int> ans;
        int start = 0;
        for(int i=0;i<s.size();i++){
            curr[s[i]-'a']--;
            if(curr[s[i]-'a']<0){
                while(curr[s[i]-'a']<0){
                    curr[s[start]-'a']++;
                    start++;
                }
                //cout<<i<<' '<<start<<' '<<s[i]<<endl;
                //curr = hash1;
            }
            int test = 0;
            for(int j=0;j<26;j++){
                test+=curr[j];
            }
            //cout<<p<<' '<<test<<endl;
            if(test==0)ans.push_back(start);
            if(i-start>=k-1){
                curr[s[start]-'a']++;
                start++;
            }
        }
        return ans;
    }
};