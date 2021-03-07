class Solution {
public:
    struct Node{
        bool end = false;
        unordered_map<char, Node*> hash; 
        Node(){
            end = false;
        }
    };
    bool addtoTrie(Node* trie, string s){
        bool added = false;
        //cout<<s<<endl;
        for(int i = s.size()-1;i>=0;i--){
            //cout<<"Here "<<s[i]<<endl;
            //for(auto it:trie->hash)cout<<it.first<<' ';
            //cout<<endl;
            if(trie->hash.find(s[i])==trie->hash.end()){
                trie->hash[s[i]] = new Node();
                if(i==0)trie->end = true;
                added = true;
            }
            trie = trie->hash[s[i]];
        }
        return added;
    }
    static bool compare(string a, string b){
        return a.size()>b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        Node * trie = new Node();
        int ans = 0;
        sort(words.begin(), words.end(), compare);
        for(int i=0;i<words.size();i++){
            //cout<<words[i]<<endl;
            if(addtoTrie(trie, words[i]))ans+=words[i].size()+1;
        }
        return ans;
    }
};