/*
这个就是莫名其妙跑起来了吗，
其实我知道思路，就是最后那个return竟然可以不要
*/ 
class Solution { // 过了
public:
    bool result = false;
    void hhhwhatever(vector<int>& nums, int beginf, int lastbeginf) { // beginf是nums的下标
        for (int i = beginf; i >= 0; i--) {
            if (nums[i] >= lastbeginf - i) {
                if (i == 0) {
                    result = true;
                    return;
                }
                hhhwhatever(nums, i - 1, i);
                return;
            }
        }
        return; // 我擦，这个可以不要
    }
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        hhhwhatever(nums, nums.size() - 2, nums.size() - 1);
        return result;
    }
};

/*
方法2
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到

        // i每次移动只能在cover的范围内移动，每移动一个元素，
        // cover得到该元素数值（新的覆盖范围）的补充，让i继续移动下去。
        // 哦，cover相当于i
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover

            cover = max(i + nums[i], cover);
            // cover每次只取 max(该元素数值补充后的范围, cover本身范围)。

            if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
        }
        return false;
    }
};
