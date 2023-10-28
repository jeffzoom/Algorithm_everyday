class Solution {
public:
// 为什么是01背包呢？
// 因为每个物品只用一次！
    int findTargetSumWays(vector<int>& nums, int target) {
        int sumnums = 0;
        for (int i = 0; i < nums.size(); i++) sumnums += nums[i];

        if ((target + sumnums) % 2 == 1) return 0; // 此时没有方案
        if (abs(target) > sumnums) return 0; // 此时没有方案
        int left = (target + sumnums) / 2; // 背包容量
        // left + right = sum
        // left - right = target

        vector<int> dp(left + 1, 0); // 填满j（包括j）这么大容积的包，有dp[j]种方法
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            // for (int j = nums[i]; j <= target; j++) {
            for (int j = left; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
                // dp[j] = max(dp[j], dp[j - nums[i]] + 1);
            }
        }
        return dp[left];


    }
};