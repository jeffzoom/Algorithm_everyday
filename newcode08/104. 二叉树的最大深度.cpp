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

// // 用层序遍历就好
// class Solution {
// public:
//     void deepOdr(TreeNode* roo, vector<vector<int>> &vec, int deep) {
//         if (roo == nullptr) return;
//         if (deep == vec.size()) vec.push_back(vector<int>());
//         deepOdr(roo->left, vec, deep + 1);
//         deepOdr(roo->right, vec, deep + 1);
//         return;
//     }
//     int maxDepth(TreeNode* root) {
//         vector<vector<int>> vec;
//         int deep = 0;
//         deepOdr(root, vec, deep);
//         return vec.size();
//     }
// };

// 2.0
class Solution {
public:
    int deepOdr(TreeNode* roo) {
        if (roo == nullptr) return 0;
        
        int leftdep = deepOdr(roo->left);
        int rightdep = deepOdr(roo->right);

        int deep = 1 + max(leftdep, rightdep);
        return deep;
    }
    int maxDepth(TreeNode* root) {
        
        return deepOdr(root);
        
    }
};