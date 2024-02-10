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
    void midtra(TreeNode* cru, vector<int>& vec) {
        if (cru == nullptr) return;
        midtra(cru->left, vec);
        vec.push_back(cru->val); //中
        midtra(cru->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> resultout;
        midtra(root, resultout);
        return resultout;
    }
};