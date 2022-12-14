class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(')');
            else if(s[i]=='{')
                st.push('}');
            else if(s[i]=='[')
                st.push(']');
            else{
                if(st.size()==0)return false;
                c = st.top();
                st.pop();
                if(c!=s[i])return false;
            }
        }
        if(st.size()!=0)return false;
        return true;
    }
};