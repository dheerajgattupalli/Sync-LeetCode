class Solution {
public:
    bool eq(vector<char> a,vector<char> b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        vector<char> pattern(26,0),s(26,0);
        for(int i=0;i<s1.size();i++){
            pattern[s1[i]-'a']++;
            s[s2[i]-'a']++;
        }
        if(eq(pattern,s))return true;
        int start=0;
        for(int i=s1.size();i<s2.size();i++){
            s[s2[start]-'a']--;
            s[s2[i]-'a']++;
            start++;
            //cout<<i<<endl;
            //while(s[s2[i]-'a']<0 && start<=i){
             //   s[s2[start]-'a']++;
                //if(pattern[s2[start]-'a']<s[s2[start]-'a']){
                //    start=i+1;
                //    s=pattern;
                //    break;
                //}
            //    start++;
             //   if(s1[0]=='c')cout<<start<<endl;
           // }
            int count=0;
            if(eq(pattern,s))return true;
        }
        //cout<<s1.size()<<' '<<s2.size()<<endl;
        return false;
    }
};