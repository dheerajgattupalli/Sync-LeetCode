class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string newS;
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z')
                newS.push_back(s[i]-'A'+'a');
            else if(s[i]>='a' && s[i]<='z')
                newS.push_back(s[i]);
            else if(s[i]>='0' && s[i]<='9')
                newS.push_back(s[i]);
        }
        cout<<newS<<endl;
        n = newS.size();
        for(int i=0;i<n/2;i++){
            if(newS[i]!=newS[n-1-i])return false;
        }
        return true;
    }
};