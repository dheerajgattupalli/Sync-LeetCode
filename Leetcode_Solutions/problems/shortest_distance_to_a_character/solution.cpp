class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> char_inds;
        for(int i=0;i<s.size();i++){
            if(s[i]==c)char_inds.push_back(i);
        }
        vector<int> ans;
        int start = 0;
        for(int i=0;i<s.size();i++){
            int dist = char_inds[start];
            if(start+1<char_inds.size()){
                if(abs(i-char_inds[start])>abs(i-char_inds[start+1]))
                    start++;
                ans.push_back(abs(i-char_inds[start]));
            }
            else ans.push_back(abs(i-char_inds[start]));
        }
        return ans;
    }
};