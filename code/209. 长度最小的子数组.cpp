// 这个超出时间限制了
/*
class Solution {
public:
    int sumNums(int& i, int& j, vector<int>& nums) {
        int su = 0;
        if (i == j) return i;
        while (i <= j) {
            su += nums[i];
            i++;
        }
        return su;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, x = INT32_MAX;
        
        while (j < nums.size()) {
            if (target < sumNums(i, j, nums)) {
                j++;
            } else {
                while (target >= sumNums(i, j, nums)) {
                    x = (x > (j - i + 1) ? (j - i + 1) : x);
                    i++;
                }
            }
        }
        return x != INT32_MAX ? x : 0;
    }
};
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, x = INT32_MAX;
        
        int sumTa = 0;
        for (int j = 0; j < nums.size(); j++) {
            sumTa += nums[j];
            // 下面应该用while，而不是if,因为i不一定只减1
            // 第二个问题是sumTa >= target写成了target >= sumTa，要细心
            while (sumTa >= target) { 
                x = (x > (j - i + 1) ? (j - i + 1) : x);
                sumTa -= nums[i++];
            }
        }
        return x != INT32_MAX ? x : 0;
    }
};
