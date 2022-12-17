class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newintervals;
        if(intervals.size()==0){
            newintervals.push_back(newInterval);
            return newintervals;
        }
        //for(auto x:intervals)
        //    newintervals.push_back(x);
        if(intervals[0][0]>newInterval[0]){
            intervals.insert(intervals.begin(),newInterval);
        }
        else{
        int newIdx = -1;
        for(int i=0;i<intervals.size();i++){
            if(newInterval[0]>=intervals[i][0]){
                if(newInterval[0]>intervals[i][1])
                    newIdx = i+1;
                else{
                    intervals[i][1] = max(intervals[i][1],newInterval[1]);
                    newIdx=-1;
                }
            }
        }
        cout<<newIdx<<endl;
        if(newIdx!=-1)intervals.insert(intervals.begin()+newIdx,newInterval);
        }
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i][0]<<' '<<intervals[i][1]<<endl;
        }
        cout<<"--"<<endl;
        newintervals.push_back(intervals[0]);
        int n = 1;
        for(int i=1;i<intervals.size();i++){
            cout<<intervals[i][0]<<' '<<intervals[i][1]<<' '<<newintervals[n-1][0]<<' '<<newintervals[n-1][1]<<endl;
            if(intervals[i][0]<=newintervals[n-1][1]){
                newintervals[n-1][1] = max(intervals[i][1],newintervals[n-1][1]);
            }
            else{
                newintervals.push_back(intervals[i]);
                n++;
            }
        }
        for(int i=0;i<newintervals.size();i++){
            //cout<<newintervals[i][0]<<' '<<newintervals[i][1]<<endl;
        }
        return newintervals;
    }
};