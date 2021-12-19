class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int j=0,n=s.size(),k=spaces.size();
        for(int i=0;i<n;i++){
            if(j<k && i==spaces[j]){
                j++;
                ans.push_back(' ');
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};