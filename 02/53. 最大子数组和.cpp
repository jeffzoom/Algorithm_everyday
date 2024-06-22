class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // // dp[i][j] 以i开头j结尾的最大连续数组，我这不是穷举吗
        // // 201 / 210 个通过的测试用例
        // if (nums.size() == 1) return nums[0];
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        // int result = INT_MIN;
        // for (int i = 0; i < nums.size(); i++) {
        //     dp[i][i] = max(INT_MIN, nums[i]);
        //     result = max(dp[i][i], result);
        // }
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         dp[i][j] = dp[i][j - 1] + nums[j];
        //         result = max(dp[i][j], result);
        //     }  
        // }
        // return result;

        // 用动态规划的方法
        // dp[i]：包括下标i（以nums[i]为结尾）的最大连续子序列和为dp[i]。
        // 一定是取最大的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        int result = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 这个逗号后面的nums[i]就保证了连续性，nums[i]是从头开始计算当前连续子序列和
            result = max(dp[i], result);
        }
        return result;


    }
};