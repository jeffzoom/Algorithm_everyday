// 蛮抽象的，遇到这种j是一个抽象值的时候
// 不好搞，跟单词拆分的j一样
// dp[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度

/*
本题最关键的是要想到dp[i]由哪些状态可以推出来，并取最大值，
那么很自然就能想到递推公式：dp[i] = max(dp[i], dp[j] + 1);

我擦，感觉
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        vector<int> dp(nums.size(), 1);
        int result = 1;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                /*
                输入   [1,3,6,7,9,4,10,5,6]
                dp下标: 0 1 2 3 4 5 6  7 8
                dp[i]:  1 2 3 4 5 3 6  4 5

                所以说每次都要判断
                */
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};