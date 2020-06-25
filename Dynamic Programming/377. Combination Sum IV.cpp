/*    // gives combination(without repeatition, [1,2])
    for(auto coin: coins):
        for(int i = 1; i <= total; i++)
            dp[i] += (i >= coin) ? dp[i - coin] : 0;

    // gives permutation ([1,2], [2,1])
    for(int i = 1; i <= total; i++)
        for(auto coin: coins)
            dp[i] += i >= coin ? dp[i -coin] : 0;
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        unsigned long long dp[target+1];
        for (int i = 0; i <= target; i++)
            dp[i] = 0;
        
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= nums[j])
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};

/*
I had a hard time understanding this, I think it's worth writing both cases on paper.

If outer loop is amount, you are considering every coin at every stage.
Let's start with amount 2: it can be made from 2 and 1 + 1, so 2 combinations. For amount 3 you would consider every coin again, which would mean that you're trying dp[amount - 1] and dp[amount - 2], which is: 2 (as there are 2 combinations for amount 2) and 1 (1 combination for amount 1).
So in this case you have 3 combinations for amount 3:
1 + 2 - taken from dp[amount - 2]
2 + 1, 1 + 1 + 1 - taken from dp[amount - 1]
You can see is one duplicate: 1 + 2 and 2 + 1
If outer loop is coins, you are NOT considering every coing at every stage
Let's assume you've already calculated all dps for coin with value 1. So for every amount there is just one combination, dp array looks like that: [1, 1, 1, 1, 1...]
Now we are doing all calculations with value 2. We are at amount 2, so again, amount 2 has 2 combinations: 1 + 1 and 2. Makes sense, no duplicates.
For amount 3 you are NOT considering every coin again - you are just considering ending every combination with 2, so ONLY dp[amount - 2].
That would make only two combinations for amount 3:
1 + 1 + 1 - taken as previous value of dp[3], calculated for coin value 1
1 + 2 - taken from dp[amount - 2]
Hopefully it shows why we don't have duplicates - all combinations are started with lowest coins, there is no way to have lowest coin at the end. You can think that you have all SORTED combinations.
*/

/*
The main idea is to define our DP properly for our requirement. Then ordering of loop and all will be dictated based on DP definition.

If ordering is important ( set of values with same sum, but different permutation are considered different)

DP[i][j] would be, number of ways to get sum j, considering ALL the element AND having i as last element. ( Finally we just need to sum all values of DP[i][target])
We find solution for a cur sum, using smaller sum solutions. ( This defines the ordering of loops )
If ordering is not important

DP[i][j] would be, number of ways to get sum j, considering only element UNTIL i. The element i can be present or not.
We find solution for a cur set of numbers, using a solution for smaller set of numbers. ( This defines the ordering of loops now )
still not clear? think the implication of definition of DP for counting permutations:

in case 1, for final answer we do sum of all values of DP[i][target]. i,e we consider all ordered set of values that give same sum of target, but have different last element. This happens even at the smaller sum result we will now reuse, and hence we get all permutations.
in case 2, the the final answer is simply combination of (a) number of sets having last element (b) number of sets not having last element. We only consider presence or absence, we are not considering ordering as separate counts. Hence this definition does not give permutations count.
*/

