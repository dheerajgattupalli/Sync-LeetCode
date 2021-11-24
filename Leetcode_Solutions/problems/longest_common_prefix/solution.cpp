class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            char c = strs[0][i];
            bool check = true;
            for(int j=1;j<strs.size();j++){
                if(i>strs[j].size() || strs[j][i]!=c)
                    check = false;
            }
            if(check)ans.push_back(c);
            else return ans;
        }
        return ans;
    }
};