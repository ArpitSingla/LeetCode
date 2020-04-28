class FirstUnique {
public:
    unordered_map<int,list<int>::iterator> m;
    list<int> l;
    FirstUnique(vector<int>& nums) {
        for(int n:nums){
            add(n);
        }
    }
    
    int showFirstUnique() {
        if(l.size()){
            return l.front();
        }
        return -1;
    }
    
    void add(int value) {
        if(m.find(value)!=m.end()){
            list<int>::iterator it=m[value];
            if(it!=l.end()){
                l.erase(it);
                m[value]=l.end();
            }
        }
        else{
            l.push_back(value);
            list<int>::iterator it=l.end();
            it--;
            m[value]=it;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */