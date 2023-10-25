class Solution {
public:
    // 最多可以装的价值为 dp[j]
    // dp[j]中的j表示容量（重量）
    // 包里最多只能装总重量的一半
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001, 0);
        int sumstone = 0;
        for (int i = 0; i < stones.size(); i++) sumstone += stones[i];
        int target = sumstone / 2; // sumstone / 2向下取整

        for (int i = 0; i < stones.size(); i++) {
            // for (int j = stones[i]; j <= target; j++) { // 这样循环的话石头可能会重复放两次，倒着循环就不会重复，我之前也经历过
            for (int j = target; j >= stones[i]; j--) { // 从大到小倒序遍历，下一行对比是从小到大对比，小的db肯定不包含stones[i]，做到一个stone避免重复放到db中
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]); 
            }
        }
        return sumstone - 2 * dp[target]; // 现在就是石头相撞，有点意思
    }
};