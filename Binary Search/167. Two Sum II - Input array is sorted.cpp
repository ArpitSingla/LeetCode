class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int low=0;
        int high=n-1;
        vector<int> v;
        if(n==0){
            return v;
        }
        if(n==1){
            v.push_back(numbers[0]);
            return v;
        }
        while(low<=high){
            if(numbers[low]+numbers[high]>target){
                high--;
            }
            else if(numbers[low]+numbers[high]<target){
                low++;
            }
            else{
                v.push_back(low+1);
                v.push_back(high+1); 
                break;
            }
        }
        return v;
    }
};