class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 | n == 1) return 1;

        // 初始化
        vector<vector<int>> dp;
        dp.push_back(vector<int>{});
        for (int i = 0; i < n; i++) {
            dp[0].push_back(1);
        }
        for (int i = 1; i < m; i++) {
            dp.push_back(vector<int>{1});
        }

        // 找规律
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i].push_back(dp[i][j - 1] + dp[i - 1][j]); // 左边+上边
            }
        }

        return dp[m - 1][n - 1];

    }
};