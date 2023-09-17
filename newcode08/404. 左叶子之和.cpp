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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) { // 1
        if (root == nullptr) return 0; // 2

        // 3
        // 当遇到左叶子节点的时候，记录数值，
        // 然后通过递归求取左子树左叶子之和，和右子树左叶子之和，
        // 相加便是整个树的左叶子之和。
        int leftsum = sumOfLeftLeaves(root->left);
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) { // 如果该节点的左节点不为空，该节点的左节点的左节点为空，该节点的左节点的右节点为空，则找到了一个左叶子
            leftsum += root->left->val;
            // leftsum = root->left->val;
        }
        int rightsum = sumOfLeftLeaves(root->right);
        int sum = leftsum + rightsum;
        return sum;
    }
};
