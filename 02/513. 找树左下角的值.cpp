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
    void depord(TreeNode* root, vector<vector<int>> &vec, int deep) {
        if (root == nullptr) return;
        if (vec.size() == deep) vec.push_back(vector<int>());
        vec[deep].push_back(root->val);
        depord(root->left, vec, deep + 1);
        depord(root->right, vec, deep + 1);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> vec;
        int deep = 0;
        depord(root, vec, deep);

        return vec[vec.size() - 1][0];
    }
};