class Solution {
public:
    int getInt(string s){
        int n=0;
        for(int i=0;i<s.size();i++){
            n = n*10 + (s[i]-'0');
        }
        return n;
    }
    vector<int> converter(string s){
        string temp;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                ans.push_back(getInt(temp));
                temp="";
            }
            else temp.push_back(s[i]);
        }
        if(temp.size()>0)ans.push_back(getInt(temp));
        while(ans.size() && ans[ans.size()-1]==0)ans.pop_back();
        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<int> a=converter(version1),b=converter(version2);
        for(int i=0,j=0;i<a.size() && j<b.size();i++,j++){
            //cout<<a[i]<<' '<<b[j]<<endl;
            if(a[i]<b[j])return -1;
            else if(a[i]>b[j])return 1;
        }
        if(a.size()>b.size())return 1;
        if(a.size()<b.size())return -1;
        return 0;
    }
};