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

// 有感觉了，不懂可以静下心来看视频
// https://www.bilibili.com/video/BV1ZG411G7Dh/?vd_source=3bafe92017da0191f9e03d4d7ee36c91 
// 在脑海中重现递归，就是函数间的一个一个嵌套，以及回溯
// 递归难在“中左右”中“左右”递归的时候要重新运行函数，重新运行的函数要适用

// 我艹，第一次，我自己看完视频之后，自己编出来递归+回溯

class Solution {
public:
    // 用前序遍历
    void traversal(TreeNode* root, vector<int> &path, vector<string> &result) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) { // 找到叶子节点了
            string spath;
            for (int i = 0; i < path.size(); i++) {
                spath += to_string(path[i]);
                if (i != path.size() - 1) spath += "->";
            }
            result.push_back(spath);
            return;
        }
        if (root->left != nullptr) {
            traversal(root->left, path, result); // 左
            path.pop_back(); // 删除最后一个元素，这个“回溯”是核心
        }
        if (root->right != nullptr) {
            traversal(root->right, path, result); // 右
            path.pop_back(); // 删除最后一个元素
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<int> path;
        vector<string> result;
        if (root == nullptr) return result;
        traversal(root, path, result);
        return result;
    }
};
