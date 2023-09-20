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

 // 和二叉树所有路径比较像

class Solution {
public:
    bool allresult;
    bool allpath(TreeNode* root, vector<int> &path, int targetSum) {
        path.push_back(root->val); // 中
        if (root->left == nullptr && root->right == nullptr) { // 找到叶子节点
            int sums = 0;
            for (auto ni : path) {
                sums += ni;
            }
            if (sums == targetSum) {
                allresult = true;
                return true;
            }  
        }
        if (root->left != nullptr) {
            allpath(root->left, path, targetSum);   // 左
            path.pop_back();                        // 回溯
        }
        if (root->right != nullptr) {
            allpath(root->right, path, targetSum);  // 右
            path.pop_back();                        // 回溯
        }

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        allresult = false;
        if (root == nullptr) return false;
        vector<int> path;
        bool results = allpath(root, path, targetSum);
        return allresult;
    }
};