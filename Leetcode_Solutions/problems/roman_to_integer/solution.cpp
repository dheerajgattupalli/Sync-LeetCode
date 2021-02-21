class Solution {
public:
    int romanToInt(string s) {
        string chars = "IVXLCDM";
        vector<int> vals{1,5,10,50,100,500,1000};
        int ans=0,prev_idx = -1;
        for(int i=0;i<s.size();i++){
            int idx = -1;
            for(int j=0;j<chars.size();j++){
                if(chars[j]==s[i])idx=j;
            }
            //cout<<idx<<' '<<prev_idx<<endl;
            if(prev_idx>=idx || prev_idx == -1)ans+=vals[idx];
            else ans+= vals[idx] - 2*vals[prev_idx];
            prev_idx = idx;
        }
        return ans;
    }
};