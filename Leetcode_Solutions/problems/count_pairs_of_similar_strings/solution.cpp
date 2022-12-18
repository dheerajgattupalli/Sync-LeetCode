class Solution {
public:
    string getUnique(string s){
        string rs;
        map<char, int> hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        for(auto x:hash){
            rs.push_back(x.first);
        }
        return rs;
    }
    int similarPairs(vector<string>& words) {
        unordered_map<string, int> hash;
        for(int i=0;i<words.size();i++){
            hash[getUnique(words[i])]++;
        }
        int ans=0;
        for(auto x:hash){
            ans+=(x.second*(x.second-1))/2;
        }
        return ans;
    }
};