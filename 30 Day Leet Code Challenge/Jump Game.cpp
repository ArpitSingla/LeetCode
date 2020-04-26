class Solution {
public:
    bool canJump(vector<int>& nums) {
        //if empty or having only one entry, it is always possible
        //as all numbers are non negative
        if (nums.size() <= 1) {
            return true;
        }
        
        //if first entry is 0, will not be possible to reach later entries
        if (nums[0] == 0) {
            return false;
        }
        
        //record the furthest index possible to be reached
        int reach = nums[0];
        
        for (int i = 0; i < nums.size() - 1; i++) {
            //when we can't go further from current entry
            //and reach so far is only up to current entry, not possible to go further
            if (nums[i] == 0 && reach <= i) {
                return false;
            }
            
            //if entry is not zero, update the max index that could be reached
            //if zero we check the next entry without updating
            if (nums[i] != 0) {                 
                reach = max(reach, i + nums[i]);
            }

        }
        
        //check if the furthest index is more than or equal to the last index
        return (reach >= nums.size() - 1);
        
    }
};