// dp[i],偷窃i号房屋之后得到的最大金额
// dp[i]=max(dp[i-2], dp[i-3])
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(), 0);
//         dp[0] = nums[0];
//         if (nums.size() > 1) dp[1] = max(nums[0], nums[1]);
//         else return dp[0]; // nums = 0 1

//         if (nums.size() > 2) dp[2] = max(nums[0] + nums[2], nums[1]);
//         else return max(dp[0], dp[1]); // nums = 0 1 2

//         // nums = 0 1 2 3 ...
//         for (int i = 3; i < nums.size(); i++) {
//             dp[i] = max(dp[i-2] + nums[i], dp[i-3] + nums[i]);
//         }
//         /*
//         输入[2,7,9,3,1]
//             下标:  0 1  2  3  4
//         目标dp[i]: 2 7 11 11 12
//         但是我的dp
//             dp[i]: 2 7 11 10 12
//         因为我的差分方程跨度是 3
//         */
        
//         // 因为我的差分方程跨度是 3 所以要判断两次max
//         int a = max(dp[nums.size() - 2], dp[nums.size() - 3]);
//         return max(dp[nums.size() - 1], a);
//     }
// };

// 上面的方法有点麻烦，试试下面的方法
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        if (nums.size() > 1) dp[1] = max(nums[0], nums[1]);
        else return dp[0]; // nums = 0 1

        // nums = 0 1 2 ...
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
