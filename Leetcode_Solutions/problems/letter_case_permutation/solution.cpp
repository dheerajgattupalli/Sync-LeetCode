class Solution {
public:
    void recurPermute(string s, vector<string> &ans, int start, string curr){
        if(start>s.size())return;
        if(curr.size()==s.size())ans.push_back(curr);
        curr.push_back(s[start]);
        recurPermute(s, ans, start+1, curr);
        curr.pop_back();
        if(s[start]<='z' && s[start]>='a'){
            curr.push_back(s[start] - 'a' + 'A');
            recurPermute(s, ans, start+1, curr );
            curr.pop_back();
        }
        else if(s[start]<='Z' && s[start]>='A'){
            curr.push_back(s[start] - 'A' + 'a');
            recurPermute(s, ans, start+1, curr);
            curr.pop_back();
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        recurPermute(S, ans, 0, "");
        return ans;
    }
};