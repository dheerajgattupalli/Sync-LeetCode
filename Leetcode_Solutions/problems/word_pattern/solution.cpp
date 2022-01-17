class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> sarr;
        string t;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                sarr.push_back(t);
           
            cout<<t<<endl;
                t.clear();
            }
            else
                t.push_back(s[i]);
        }
        sarr.push_back(t);
        if(pattern.size()!=sarr.size())return false;
        map<char,string> hash1;
        map<string,char> hash2;
        for(int i=0;i<pattern.size();i++){
      cout<<pattern[i]<< ' '<<sarr[i]<<endl;     if(hash1.find(pattern[i])==hash1.end())
                hash1[pattern[i]]=sarr[i];
 else if(hash1[pattern[i]]!=sarr[i])
     return false;
     

            if(hash2.find(sarr[i])==hash2.end())
                hash2[sarr[i]]=pattern[i];
 else if(hash2[sarr[i]]!=pattern[i])
     return false;
        }
        return true;
    }
};