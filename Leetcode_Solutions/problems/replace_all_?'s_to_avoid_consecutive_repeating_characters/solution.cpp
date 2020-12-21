class Solution {
public:
    string modifyString(string s) {
        string ans = s;
        for(int i=0;i<s.size();i++){
            if(ans[i]=='?')
            for(int j=0;j<26;j++){
                bool set_val  = true;
                if(i>0 && ans[i-1]=='a'+j)set_val = false;
                if(i<s.size()-1 && ans[i+1]=='a'+j)set_val = false;
                if(set_val){
                    ans[i] = 'a'+j;
                    break;
                }
            }
        }
        return ans;
    }
};