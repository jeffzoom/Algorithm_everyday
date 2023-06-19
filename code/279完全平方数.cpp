/*
背包重量 n
物品 1^2 2^2 3^2 ... 价值=重量
物品可以重复
dp[j]：凑足总和为j的完全平方数的最少数量是dp[j] 
1 <= n <= 10^4  

*/

// 我一边过啊 我牛逼 跟零钱兑换一样
class Solution {
public:
    int numSquares(int n) {
        vector<int> vec;
        for (int i = 0; i < 100; i++) {
            vec.push_back(i*i);
        }
        vector<int> dp(10001, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < vec.size(); i++) {
            for (int j = vec[i]; j <= n; j++) {
                if (dp[j - vec[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - vec[i]] + 1); // 当前是vec[i]
                }
            }
        }
        if (dp[n] != INT_MAX) return dp[n];
        return -1;


    }
};