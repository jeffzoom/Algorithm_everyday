class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {         // 背包 先遍历背包，顺序就会重复
            for (int j = 0; j < nums.size(); j++) { // 物品
                if (i - nums[j] >= 0 && dp[i - nums[j]] < INT_MAX - dp[i]) { 
                    // C++测试用例有两个数相加超过int的数据，
                    // 所以需要在if里加上dp[i] < INT_MAX - dp[i - num]。
                    // 其实就是dp[i] + dp[i - nums[j]] < INT_MAX
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};