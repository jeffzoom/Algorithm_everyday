class Solution {
public:
    int integerBreak(int n) {
        // dp[i]：拆分数字i，可以得到的最大乘积为dp[i]。这句话我看题解了

        vector<int> dp(n + 1, 0);
        int tmp = 0;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < i; j++) {
                // 下面两个max对比很重要
                
                dp[i] = max(dp[i], max( (i - j) * j, dp[i - j] * j ));
            }
        }

        return dp[n];
    }
};