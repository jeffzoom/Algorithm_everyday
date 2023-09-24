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

class Solution { // 没看题解，自己搞定的递归
public:
    TreeNode* tempsave = nullptr;
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;

        if (root->val == val) {
            tempsave = root;
            return root;
        }
        searchBST(root->left, val);
        searchBST(root->right, val);
        return tempsave;
    }
};
