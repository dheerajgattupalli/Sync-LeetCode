class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int count=0,n=position.size();
        for(int i=0;i<n;i++)
            count+=position[i]%2;
        return min(count,n-count);
    }
};