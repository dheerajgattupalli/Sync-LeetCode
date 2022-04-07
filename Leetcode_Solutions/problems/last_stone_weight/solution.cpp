class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int i=0;i<stones.size();i++){
            heap.push(stones[i]);
        }
        int first=heap.top();
        heap.pop();
        if(heap.size()==0)return first;
        while(!heap.empty()){
            int second = heap.top();
            heap.pop();
            //cout<<first<<' '<<second<<endl;
            int diff = first-second;
            if(diff){
             //   cout<<diff<<endl;
                heap.push(diff);
            }
            if(!heap.empty()){
                first = heap.top();
                heap.pop();
                if(heap.empty())return first;
            }
           // cout<<'s'<<heap.size()<<endl;
        }
        if(heap.size()==0)return 0;
        return heap.top();
    }
};