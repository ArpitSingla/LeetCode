class StockSpanner {
public:
    stack<int> s;
    int count=-1;
    vector<int> ans;
    StockSpanner() {
        
    }
    int solve(int price,int count){
        ans.push_back(price);
        int temp;
        if(count==0){
            s.push(count);
            return 1;
        }
        else{
            while(!s.empty() && price>=ans[s.top()]){
                s.pop();
            }
            if(s.empty()){
                temp=count+1;
            }
            else{
                temp=count-s.top();
            }
            s.push(count);
        }
        return temp;
    }
    int next(int price) {
        return solve(price,++count);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */