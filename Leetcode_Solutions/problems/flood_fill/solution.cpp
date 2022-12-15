class Solution {
public:
    void floodFillRecur(vector<vector<int>>& image, int sr, int sc, int color, int pc) {
        int n = image.size(), m = image[0].size();
        cout<<sr<<' '<<sc<<endl;
        if(image[sr][sc]==color)return;
        image[sr][sc]=color;
        if(sr+1<n && image[sr+1][sc]==pc){
            floodFillRecur(image, sr+1, sc, color, pc);
        }
        if(sc+1<m && image[sr][sc+1]==pc){
            floodFillRecur(image, sr, sc+1, color, pc);
        }
        if(sr-1>=0 && image[sr-1][sc]==pc){
            floodFillRecur(image, sr-1, sc, color, pc);
        }
        if(sc-1>=0 && image[sr][sc-1]==pc){
            floodFillRecur(image, sr, sc-1, color, pc);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        floodFillRecur(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};