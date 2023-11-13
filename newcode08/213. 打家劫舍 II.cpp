class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp1(nums.size() - 1, 0);
        vector<int> dp2(nums.size() - 1, 0);
        // 考虑两种情况，掐头去尾

        // 去除nums尾元素
        for (int i = 0; i < dp1.size(); i++) {
            if (i - 2 >= 0) {
                dp1[i] = max( dp1[i - 1], max(dp1[i - 2] + nums[i] , nums[i]) );
            } else if (i - 1 >= 0) {
                dp1[i] = max(dp1[i - 1], nums[i]);
            } else {
                dp1[i] = max(dp1[i], nums[i]);
            }   
        }

        // 去除nums头元素
        for (int i = 0; i < dp2.size(); i++) {
            if (i - 2 >= 0) {
                dp2[i] = max( dp2[i - 1], max(dp2[i - 2] + nums[i + 1] , nums[i + 1]) );
            } else if (i - 1 >= 0) {
                dp2[i] = max(dp2[i - 1], nums[i + 1]);
            } else {
                dp2[i] = max(dp2[i], nums[i + 1]);
            }   
        }
        return max(dp1[nums.size() - 2], dp2[nums.size() - 2]);
    }
};