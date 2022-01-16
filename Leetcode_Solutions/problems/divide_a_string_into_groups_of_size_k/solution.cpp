class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size(),i=0;
        string temp;
        for(i=1;i<=n;i++){
            temp.push_back(s[i-1]);
            if(i%k==0){
                ans.push_back(temp);
                temp.clear();
            }
        }
        i--;
        if(i%k){
            for(int j=0;j<(k-i%k);j++)temp.push_back(fill);
            ans.push_back(temp);
        }
        return ans;
    }
};