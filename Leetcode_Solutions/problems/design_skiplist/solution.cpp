class Skiplist {
public:
    list<int> skip_list;
    Skiplist() {
        skip_list.clear();
    }
    
    bool search(int target) {
        //list<int> head = skip_list;
        for(auto it:skip_list){
            if(it==target)return true;
        }
        return false;
    }
    
    void add(int num) {
        skip_list.push_front(num);
    }
    
    bool erase(int num) {
        list<int>::iterator it=skip_list.begin();
        for(int val:skip_list){
            if(val==num)
                break;
            it++;
        }
        if(it!=skip_list.end()){
            skip_list.erase(it);
            return true;
        }
        return false;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */