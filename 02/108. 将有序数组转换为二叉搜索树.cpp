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

// fuck 看到切割之后就一边过了，切割，切割
class Solution {
public:
    TreeNode* buidtree(vector<int>& nums) {
        if (nums.size() == 1) {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }
        int i = nums.size() / 2; // 0 1 2 其中3/2=1 // 0 1 2 3 其中4/2=2
        TreeNode* root = new TreeNode(nums[i]);

        // 切割，看完题解才想到的
        vector<int> numsleft(nums.begin(), nums.begin() + i);
        if (numsleft.size() >= 1) root->left = buidtree(numsleft);

        vector<int> numsright(nums.begin() + i + 1, nums.end());
        if (numsright.size() >= 1) root->right = buidtree(numsright);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* result = buidtree(nums);
        return result;
    }
};


