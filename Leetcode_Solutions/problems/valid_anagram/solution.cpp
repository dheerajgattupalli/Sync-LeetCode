class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,int> hash_map;
        for(int i=0;i<s.size();i++){
            hash_map[s[i]]++;
            hash_map[t[i]]--;
        }
        for(auto it:hash_map){
            cout<<it.first<<' '<<it.second<<endl;
            if(it.second!=0)return false;
        }
        return true;
    }
};