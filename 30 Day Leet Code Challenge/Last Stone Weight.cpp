class Solution{
public:
    int lastStoneWeight(vector<int>& stones){
        int max, second_max, diff;
        make_heap(stones.begin(),stones.end());
        while(stones.size() > 1){
            max = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            second_max = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            diff = max - second_max;
            if(diff != 0){
                stones.push_back(diff);
                push_heap(stones.begin(),stones.end());
            }
        }
        if(stones.empty()){
            return 0;
        }
        else{
            return stones.front();
        }
    }
};