/*
从能跳跃到最小跳跃数
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        vector<int> dp(nums.size(), INT_MAX); // dp[i] 到达i的最小步数为dp[i]
        dp[0] = 0;
        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            if (i <= nums.size() - 1) { // 只是保护，防止nums[i]越界
                cover = max(i + nums[i], cover); // cover是可达最大位置的下标
            }
            /*
            移动下标只要遇到当前覆盖最远距离的下标，直接步数加一，不考虑是不是终点的情况。
            直接喷射 cover覆盖的位置统一dp[i] + 1 或取 min dp[i + tmp]
            */ 
            if (i <= nums.size() - 1) { // 只是保护，防止nums[i]越界
                for (int tmp = 1; tmp <= nums[i]; tmp++) {

                    if (i + tmp <= nums.size() - 1) { // 只是保护，防止dp[i + tmp]越界
                        dp[i + tmp] = min(dp[i + tmp], dp[i] + 1);
                    }
                }
            }
        }
        //可以简写，为了让我以后已经看的清除
        if (dp[nums.size() - 1] != INT_MAX) return dp[nums.size() - 1]; 
        return dp[nums.size() - 1];
    }
};