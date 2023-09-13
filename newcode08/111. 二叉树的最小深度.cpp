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
    int getdep(TreeNode* root, int deep) { // 我要用后序遍历 左右中
        // if (root->left == nullptr && root->right == nullptr) return deep;

        // 确定终止条件 从下往上数 0 1 2 3,[15 7]的高度是1
        if (root == nullptr) return 0; // 终止条件也是遇到空节点返回0，表示当前节点的高度为0。
        // 递归的过程中遇到空节点了为终止，返回0，表示当前节点为根节点的树高度为0
        // 返回0 那么意味着上面层的叶子不为空

        // 所以，如果左子树为空，右子树不为空，说明最小深度是 1 + 右子树的深度。
        // 反之，右子树为空，左子树不为空，最小深度是 1 + 左子树的深度。 
        // 最后如果左右子树都不为空，返回左右子树深度最小值 + 1。

        int leftdep = getdep(root->left, deep); // 左
        int rightdep = getdep(root->right, deep); // 右

        if (root->left == nullptr && root->right != nullptr) return 1 + rightdep;
        if (root->left != nullptr && root->right == nullptr) return 1 + leftdep;

        int results = 1 + min(rightdep, leftdep);
        return results;
    }
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        // if (root->left == nullptr && root->right == nullptr) return 1;
        int deep = 1;
        int results = getdep(root, deep);
        return results;
    }
};

