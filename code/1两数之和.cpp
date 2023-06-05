class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 一定会存在答案啊，还只有一个答案，出题的也不容易，哈哈
        int numSum= 0, j = 0;
        vector<int> outa;
        // while (numSum != target) {
        for (int i = 0; i < nums.size(); i++) {
            for (j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    outa.push_back(i);
                    outa.push_back(j);
                    return outa;
                }
            }
        }
        return outa;
        // }
    }
};
