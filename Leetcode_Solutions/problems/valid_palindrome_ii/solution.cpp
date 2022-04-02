class Solution {
public:
    bool checkSubPalindrome(string s, int start, int end){
        //cout<<s<<' '<<start<<' '<<end<<endl;
        for(int i=0;i<=(end-start)/2;i++){
            if(s[start+i]!=s[end-i])return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]){
                return checkSubPalindrome(s,i,s.size()-2-i) 
                    || checkSubPalindrome(s,i+1,s.size()-i-1); 
            }
        }
        return true;
    }
};