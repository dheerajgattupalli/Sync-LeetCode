class Solution {
public:
    struct trie{
        bool end;
        //unordered_map<char, struct trie *> next;
        struct trie* next[2];
        trie(){
            end=true;
            next[0] = NULL;
            next[1] = NULL;
        }
        trie(char c){
            end=true;
            next[c-'0'] = new trie();
        }
    };
    void insert(struct trie *all_nums, string s){
        for(int i=0;i<32;i++){
            if(all_nums->next[s[i]-'0']==NULL)
                all_nums->next[s[i]-'0'] = new trie();
            if(i==s.size()-1)all_nums->end=true;
            all_nums = all_nums->next[s[i]-'0'];
        }
    }
    string ntos(int n){
        string s;
        for(int i=0;i<32;i++){
            s.push_back(n%2+'0');
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int ston(string s){
        int n=0;
        //for(int i=31;i>=0;i--){
        for(int i=0;i<32;i++){
            n=n*2+((s[i]-'0')%2);
        }
        return n;
    }
    string closest(struct trie *all_nums, string s){
        string build;
        //cout<<"Finding -> "<<s<<endl;
        for(int i=0;i<32;i++){
            //cout<<s[i]<<' ';
            if(all_nums->next[1-(s[i]-'0')]!=NULL){
                //cout<<"Here1"<<endl;
                all_nums = all_nums->next[1-(s[i]-'0')];
                build.push_back('1');
            }
            //if(all_nums->next.find(s[i])!=all_nums->next.end()){
                //cout<<"Here0"<<endl;
            else{
                all_nums = all_nums->next[s[i]-'0'];
                build.push_back('0');
            }
            //cout<<build[i]<<endl;
        }
        return build;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        struct trie *all_nums = new trie();
        //for(int i=0;i<nums.size();i++){
        //}
        insert(all_nums, ntos(nums[0]));
        int ans = 0;
        
        for(int i=1;i<nums.size();i++){
            string s = ntos(nums[i]);
            string s_out = closest(all_nums, s);
            int curr = ston(s_out);
            //cout<<nums[i]<<"--"<<s_out<<' '<<ston(s_out)<<endl;
            ans = max(ans, curr);
            s = ntos(nums[i]);
            insert(all_nums, s);
        }
        return ans;
    }
};