///*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1, cetr = (i+j)/2;
        while (i <= j) { 
            if (nums[cetr] > target) {
                j = cetr - 1; // 之前没有减一和加一，导致时间复杂度很高
                cetr = (i+j)/2;
            }
            else if(nums[cetr] < target) {
                i = cetr + 1;
                cetr = (i+j)/2;
            }
            else {
                return cetr;
            }
        }
        return -1;
    }
};
//*/

/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};
*/


