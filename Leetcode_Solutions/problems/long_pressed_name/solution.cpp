class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int curr = 0;
        for(int i=0;i<typed.size();i++){
            if(typed[i]==name[curr]){
                curr++;
                continue;
            }
            if(curr>0 && typed[i]==name[curr-1])continue;
            return false;
        }
        if(curr!=name.size())return false;
        return true;
    }
};