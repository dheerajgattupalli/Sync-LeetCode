class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z')
                ans.push_back('a' + s[i]-'A');
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};