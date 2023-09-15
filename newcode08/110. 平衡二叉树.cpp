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

 // 任何节点的左右子树高度
class Solution {
public:
    int balencetree(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftbt = balencetree(root->left); // 左节点的高度
        if (leftbt == -1) return -1;
        int rightbt = balencetree(root->right); // 右节点的高度
        if (rightbt == -1) return -1;

        if (abs(leftbt - rightbt) > 1) return -1;

        // 返回当前节点的高度
        else return 1 + max(leftbt, rightbt); // 以当前节点为根节点的树的最大高度
    }
    bool isBalanced(TreeNode* root) {
        return balencetree(root) == -1 ? false : true;
    }
};

