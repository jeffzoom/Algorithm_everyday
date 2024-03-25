/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution { // 原始暴力版，没有用到二叉搜索树特性
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (root == nullptr) return nullptr;
//         if (root->val == p->val || root->val == q->val) return root;

//         TreeNode* leftd = lowestCommonAncestor(root->left, p, q);
//         TreeNode* rightd = lowestCommonAncestor(root->right, p, q);

//         if (leftd != nullptr && rightd != nullptr) return root;

//         if (leftd != nullptr && rightd == nullptr) return leftd;
//         if (leftd == nullptr && rightd != nullptr) return rightd;
//         return nullptr;
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr; // 中
        // 左
        if (root->val > p->val && root->val > q->val) {
            TreeNode* leftd = lowestCommonAncestor(root->left, p, q);
            if (leftd != nullptr) return leftd;
        }
        // 右
        if (root->val < p->val && root->val < q->val) {
            TreeNode* rightd = lowestCommonAncestor(root->right, p, q);
            if (rightd != nullptr) return rightd;
        }

        return root; // 如果p q分别在左右两个子树上，那就直接返回根节点
    }
};