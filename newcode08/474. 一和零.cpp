class Solution {
public:
    // 字符串中0的个数
    int strsnums0 (string str0) {
        int nums0 = 0;
        for (int i = 0; i < str0.size(); i++) {
            if (str0[i] == '0') nums0++; // 服了，最后又是因为字符和字符串的问题。之前写成了if (str0[i] == 0) nums0++;，0没有带字符标志，str0[i]的返回值是字符
        }
        return nums0;
    }
    // 字符串中1的个数
    int strsnums1 (string str1) { 
        return str1.size() - strsnums0(str1);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // m+1行，n+1列
        // dp[0][0] = 1;
        int num0 = 0, num1 = 0;

        // 初始化1行1列为1
        // dp[0] = vector<int>(n + 1, 1);
        // for (int i = 1; i < m + 1; i++) dp[i][0] = 1;

        for (string st : strs) {
            num0 = strsnums0(st);
            num1 = strsnums1(st);
            for (int i = m; i >= num0; i--) {
                for (int j = n; j >= num1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
        }

        return dp[m][n];

    }
};