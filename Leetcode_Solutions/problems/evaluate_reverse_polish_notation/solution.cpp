class Solution {
public:
    int stringtoint(string s){
        bool neg = s[0]=='-';
        int n = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-')continue;
            n= n*10 + (s[i]-'0');
        }
        if(neg)n*=-1;
        return n;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        long long int a,b;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="*"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                a = a*b;
                st.push(a);
            }
            else if(tokens[i]=="/"){
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                a = a/b;
                st.push(a);
            }
            else if(tokens[i]=="+"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                a = a+b;
                st.push(a);
            }
            else if(tokens[i]=="-"){
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                a = a-b;
                st.push(a);
            }
            else{
                st.push(stringtoint(tokens[i]));
                //cout<<st.top()<<endl;
            }
        } 
        if(!st.empty()){
            a = st.top();
        }
        return a;
    }
};