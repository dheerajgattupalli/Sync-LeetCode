class Solution {
public:
    int stringtoint(string s){
        int n=0,l = s.size();
        for(int i=0;i<l;i++){
            n=n*10+(s[i]-'0');
        }
        return n;
    }
    string decodeString(string s) {
        string ans="",temp="";
        stack<string> st;
        for(int i=0;i<s.size();i++){
            //cout<<s<<i<<' '<<temp<<endl;
            if(s[i]=='['){
                if(temp.size()>0)st.push(temp);
                temp = "";
            }
            else if(s[i]>='0' && s[i]<='9' && temp.size()>0 &&
                   (temp[0]<'0' || temp[0]>'9')){
                st.push(temp);
                temp=s[i];
            }
            else if(s[i]==']'){
                string top_s=st.top();
                st.pop();
                //cout<<"top->"<<top_s<<endl;
                while(top_s[0]<'0' || top_s[0]>'9'){
                    temp = top_s + temp;
                    top_s = st.top();
                    st.pop();
                    if(st.empty())break;
                }
                //cout<<s<<" "<<i<<' '<<temp<<" "<<top_s<<endl;
                int repeat = stringtoint(top_s);
                string new_temp = "";
                for(int j=0;j<repeat;j++){
                    new_temp += temp;
                }
                st.push(new_temp);
                temp="";
            }
            else 
                temp.push_back(s[i]);
        }
        if(temp.size()>0)st.push(temp);
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};