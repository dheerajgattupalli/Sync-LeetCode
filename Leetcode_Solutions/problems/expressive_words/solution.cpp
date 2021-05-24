class Solution {
public:
    struct Node{
        unordered_map<char, Node*> map_;
        bool end;
        int count;
        Node(){
            end = true;
            count=1;
        }  
    };
    void addString(Node *trie, string s){
        for(int i=0;i<s.size();i++){
            if(trie->map_.find(s[i])==trie->map_.end()){
                trie->map_[s[i]] = new Node();
            }
            else{
                trie->map_[s[i]]->count+=1;
            }
            int j=i+1;
            while(s[i]==s[j] && j<s.size()){
                j++;
            }
            //cout<<s<<' '<<i<<' '<<s[i]<<' '<<j<<endl;
            int count = j-i;
            trie = trie->map_[s[i]];
            trie->count=count;
            i=j-1;
            if(i==s.size()-1)trie->end=true;
        }
    }
    
    bool checkString(Node *trie, string s){
        for(int i=0;i<s.size();i++){
            if(!trie || trie->map_.find(s[i])==trie->map_.end())return false;
            else{
                int j=i+1;
                while(s[i]==s[j] && j<s.size()){
                    j++;
                }
                //cout<<s<<' '<<i<<' '<<j<<' '<<s.size()<<endl;
                int count = j-i;
                if(count==trie->map_[s[i]]->count || (trie->map_[s[i]]->count>=3 && trie->map_[s[i]]->count>count)){
                    i=j-1;
                }
                else{
                    //cout<<s<<' '<<i<<' '<<s[i]<<' '<<count<<' '<<trie->map_[s[i]]->count<<endl;
                    return false;
                }
                trie = trie->map_[s[i]];
            }       
        }
        //cout<<trie->map_.size()<<endl;
        if(trie->map_.size()==0){
            return true;
        }
        return false;
    }
    int expressiveWords(string s, vector<string>& words) {
        Node *trie = new Node();
        addString(trie, s);
        int ans = 0;
        for(int i=0;i<words.size();i++){
            if(checkString(trie, words[i]))ans++;
        }
        return ans;
    }
};