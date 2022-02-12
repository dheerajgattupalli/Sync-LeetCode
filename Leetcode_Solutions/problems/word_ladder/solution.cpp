class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> h1,h2;
        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList[i].size();j++){
                string t = wordList[i];
                t[j]='*';
                h1[wordList[i]].push_back(t);
                h2[t].push_back(wordList[i]);
            }
        }
        for(int j=0;j<beginWord.size();j++){
            string t = beginWord;
            t[j]='*';
            h1[beginWord].push_back(t);
            h2[t].push_back(beginWord);
        }
        if(h1.find(endWord)==h1.end())
            return 0;
        unordered_map<string,int> dists;
        int n = wordList.size(),m=wordList[0].size();
        for(auto x:h1){
            dists[x.first]=n*m*10;
            //cout<<x.first<<' ';
            //for(auto y:x.second){
            //    cout<<y<<' ';
            //}
            //cout<<endl;
        }
        for(auto x:h2){
            dists[x.first]=n*m*10;
            //cout<<x.first<<' ';
            //for(auto y:x.second){
            //    cout<<y<<' ';
            //}
           // cout<<endl;
        }
        queue<string> q1;
        q1.push(beginWord);
        int ans =1,depth=0;
        string prev=beginWord;
        while(!q1.empty()){
            queue<string> q2;
            if(h1.find(q1.front())!=h1.end())depth++;
            while(!q1.empty()){
                string t=q1.front();
                q1.pop();
                if(t==endWord)return depth;
                dists[t]=min(ans, dists[t]);
                //cout<<t<<' '<<dists[t]<<' '<<ans<<endl;
                if(h1.find(t)!=h1.end()){
                    //cout<<"going in 1:"<<h1[t].size()<<endl;
                    for(auto x:h1[t]){
                        if(depth<dists[x]){
                            q2.push(x);
                            //cout<<"1 pushing"<<x<<endl; 
                            dists[x] = depth;
                        }
                    }
                }
                else if(h2.find(t)!=h2.end()){
                    //cout<<"going in 2:"<<h2[t].size()<<endl;
                    for(auto x:h2[t]){
                        if(depth<dists[x]){
                            dists[x]=depth;
                            //cout<<"2 pushing"<<x<<endl;
                            q2.push(x);
                        }
                    }
                    //ans--;
                }
            }
            ans++;
            q1=q2;
        }
        if(dists[endWord]==n*m*10)return 0;
        return dists[endWord];
    }
};