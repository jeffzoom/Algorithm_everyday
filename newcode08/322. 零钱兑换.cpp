class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { // 4  总金额为amount
        // dp[j]：凑足总额为j所需钱币的最少个数为dp[j]
        // j 和 dp[j] 真是容易搞错啊
        vector<int> dp(amount + 1, INT_MAX);         // 0 1 2 3 4
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++) { 
            for(int j = coins[i]; j <= amount; j++) { 
                if (dp[j - coins[i]] != INT_MAX) // 如果dp[j - coins[i]]是初始值则跳过
                    /*
                    这是一个限制，如coins = [3,2,5]; amount = 11
                    j = 3，先是 dp=[0 2147483647 2147483647 1 2147483647 2147483647 ...]
                    然后没有限制 j = 4 因为 
                                    dp[4-3] + 1 = dp[1] + 1 = 2147483647 + 1 = -2147483648
                            所以    dp=[0 2147483647 2147483647 1 -2147483648 2147483647 ...]
                            然后事态就失控了
                            int超出范围，溢出，牛逼plus
                    */
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                    // dp[j - coins[i]]
                    // 当前钱币的金额为coins[i]
                    // 凑足总额为j - coins[i]的最少个数为dp[j - coins[i]]，
                    // 那么只需要加上一个钱币coins[i]即dp[j - coins[i]] + 1就是dp[j]
                    // 牛逼！！！ 牛逼！！！
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];

    }
};  