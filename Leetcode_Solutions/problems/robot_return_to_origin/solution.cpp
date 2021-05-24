class Solution {
public:
    pair<int,int> getUpdated(pair<int,int> inp, char move){
        switch(move){
            case 'U':
                inp.second+=1;
                break;
            case 'D':
                inp.second-=1;
                break;
            case 'L':
                inp.first-=1;
                break;
            case 'R':
                inp.first+=1;
                break;
        }
        return inp;
    }
    bool judgeCircle(string moves) {
        pair<int, int> inp = make_pair(0,0),start=make_pair(0,0);
        for(int i=0;i<moves.size();i++){
            inp = getUpdated(inp, moves[i]);
        }
        if(inp==start)return true;
        return false;
    }
};