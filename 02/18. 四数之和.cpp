class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> outall;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && nums[i] >= 0) return outall;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1, right = nums.size() - 1;

                while (left < right) {
                    // [0,0,0,1000000000,1000000000,1000000000,1000000000] 超出范围 需要加long
                    // int是4字节，范围是-2147483648~2147483647
                    if ((long) nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else if ((long) nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else {
                        outall.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1] ) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return outall;
    }
};