class WordDictionary {
public:
    bool end;
    unordered_map<char, WordDictionary *> next;
    WordDictionary() {
        end=false;
        next.clear();
    }
    
    void addWord(string word) {
        WordDictionary *temp = this;
        for(int i=0;i<word.size();i++){
            if(temp->next.find(word[i])==temp->next.end()){
                temp->next[word[i]] = new WordDictionary();
            }
            temp = temp->next[word[i]];
            if(i==word.size()-1)temp->end=true;
        }
    }
    
    bool search(string word) {
        WordDictionary *temp = this;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.' && temp){
                for(auto x:temp->next){
                    bool ans= x.second->search(word.substr(i+1,word.size()-i-1));
                    if(ans)return true;
                }
                return false;
            }
            else if(!temp || temp->next.find(word[i])==temp->next.end())return false;
            else temp = temp->next[word[i]];
        }
        return temp->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */