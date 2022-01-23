class Solution {
public:
    int countDigits(int n){
        int ans=0;
        while(n>0){
            ans++;
            n/=10;
        }
        return ans;
    }
    int my_atoi(string s){
        int n = 0;
        for(int i=0;i<s.size();i++){
            n = n*10+s[i]-'0';
        }
        return n;
    }
    string getInt(string s){
        for(int i=0;i<s.size();i++){
            s[i]+=1;
            if(s[i]>'9')return "";
        }
        return s;
    }
    vector<int> sequentialDigits(int low, int high) {
        int d1 = countDigits(low),d2=countDigits(high);
        vector<int> ans;
        while(d1<=d2){
            string s;
            for(int i=0;i<d1;i++){
                s.push_back('0'+i+1);
            }
            int sInt = my_atoi(s);
            //cout<<s<<' '<<sInt<<endl;
            while(sInt<low){
                s = getInt(s);
                if(s.size()==0)break;
                sInt = my_atoi(s);
            }
            while(s.size() && sInt<=high){
                ans.push_back(sInt);
                s = getInt(s);
                //cout<<s<<endl;
                if(s.size()==0)break;
                sInt = my_atoi(s);
            }
            d1++;    
        }
        return ans;
    }
};