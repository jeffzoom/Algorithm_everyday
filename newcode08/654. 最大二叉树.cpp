/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 大致看了一下题解之后一遍过，对递归认识更深了，果然要实践
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) { // 1、确定递归函数的参数和返回值
        // 用前序遍历

        TreeNode* note = new TreeNode(0); // 临时创建一个，val为0
        if (nums.size() == 1) { // 2、确定终止条件
            note->val = nums[0];
            return note;
        }

        // 确定单层递归的逻辑，用前序遍历
        // 中
        int maxnum = 0; // 数组最大值
        int maxnumIndex = 0; // 数组最大值的下标
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxnum) {
                maxnum = nums[i];
                maxnumIndex = i;
            }
        }
        note->val = maxnum;

        // 左 切割
        if (maxnumIndex > 0) {
            vector<int> numsleft(nums.begin(), nums.begin() + maxnumIndex); 
            // 如下标 0 1 2，2是maxnumIndex数组最大值的下标，拷贝构造函数只拷贝0 和 1，但是指针要指到2
            // 类似nums.end()指向的是元素的最后一个值再+1
            note->left = constructMaximumBinaryTree(numsleft);
        }

        // 右
        if (maxnumIndex < nums.size() - 1) {
            vector<int> numsright(nums.begin() + maxnumIndex + 1, nums.end());
            note->right = constructMaximumBinaryTree(numsright);
        }

        return note;
    }
};