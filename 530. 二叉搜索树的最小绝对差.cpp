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

// 前序遍历 
// 注意是二叉搜索树，二叉搜索树可是有序的。
// 两个节点可以不相邻？？？？？
// class Solution { // 没有通过
// public:
//     int minatob = INT_MAX;
//     int getMinimumDifference(TreeNode* root) {
//         if (root == nullptr) return minatob;
//         if (root->left == nullptr && root->right == nullptr) return minatob;

//         if (root->left != nullptr) {
//             minatob = min(minatob, abs(root->val - root->left->val));
//         }
//         if (root->right != nullptr) {
//             minatob = min(minatob, abs(root->val - root->right->val));
//         }
//         getMinimumDifference(root->left);
//         getMinimumDifference(root->right);

//         return minatob;
//     }
// };

// 两个节点可以不相邻？？？？？
// 二叉搜索树可是有序的。所以中序遍历
class Solution {
public:
    int minatob = INT_MAX;
    void midlf(TreeNode* root, vector<int> &vec) {
        if (root == nullptr) return;
        midlf(root->left, vec);
        vec.push_back(root->val);
        if (vec.size() > 1) minatob = min(abs(*(vec.end() - 2) - *(vec.end() - 1)), minatob);
        midlf(root->right, vec);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        midlf(root, vec);

        return minatob;
    }
};