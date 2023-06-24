/*class Solution {
public:
    void quickSort(vector<int>& q, int l, int r) {
        if (l >= r) return;

        int x = q[l], i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (q[i] < x);
            do j--; while (q[j] > x);
            if (i < j) swap(q[i], q[j]);
        }
        quickSort(q, l, j);
        quickSort(q, j + 1, r);
    }
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            nums[i] *=nums[i];
        }
        quickSort(nums, 0, nums.size() - 1);
        // sort(nums.begin(), nums.end()); // 快速排序 shit 可以直接这样
        return nums;
    }
};*/

// 双指针法 前后指针
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, x = j;
        vector<int> q(nums.size());
        while (i != j) {
            if (nums[i]*nums[i] > nums[j]*nums[j]) {
            q[x--] = nums[i]*nums[i];
            i++;
            } else {
                q[x--] = nums[j]*nums[j];
                j--;
            }
        }
        q[x] = nums[j]*nums[j];
        return q;
    }
};

