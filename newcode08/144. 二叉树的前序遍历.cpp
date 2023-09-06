/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : 
                val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     void preOrder(TreeNode* cur, vector<int>& vec) {
//         if (cur == nullptr) return;
//         vec.push_back(cur->val);    // 中
//         preOrder(cur->left, vec);   // 左
//         preOrder(cur->right, vec);  // 右
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> out_tree;
//         preOrder(root, out_tree); //递归
//         return out_tree;
//     }
// };




class Solution {
public:
    void levOrd(vector<int> &vec, TreeNode* roo) {
        if (roo == nullptr) return;
        vec.push_back(roo->val);
        
        levOrd(vec, roo->left);
        // lev重新变成0
        levOrd(vec, roo->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        
        // if (root == nullptr) return vec;
        levOrd(vec, root);
        return vec;
    }
};