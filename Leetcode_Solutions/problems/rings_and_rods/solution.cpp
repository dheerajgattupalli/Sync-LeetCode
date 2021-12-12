class Solution {
public:
    int countPoints(string rings) {
        vector<unordered_set<char>> rods(10,unordered_set<char>()); 
        for(int i=0;i<rings.size();i+=2){
            int t = rings[i+1]-'0';
            rods[t].insert(rings[i]);
        }
        int ans = 0;
        for(auto x:rods){
            if(x.size()==3)ans++;
        }
        return ans;
    }
};