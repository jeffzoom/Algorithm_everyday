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

// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if (root == nullptr) return nullptr;
//         if (root->val > val && root->left == nullptr) {
//             TreeNode* newtre = new TreeNode(val);
//             root->left = newtre;
//             return root;
//         }
//         if (root->val < val && root->right == nullptr) {
//             TreeNode* newtre = new TreeNode(val);
//             root->right = newtre;
//             return root;
//         }

//         insertIntoBST(root->left, val);
//         insertIntoBST(root->right, val);
//         return root;
//     }
// };

// 真乱啊 看视频
// https://www.bilibili.com/video/BV1Et4y1c78Y/?share_source=copy_web&vd_source=3bafe92017da0191f9e03d4d7ee36c91
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) { // 找到要插入的节点的位置，在实例1：节点7的下一层
            TreeNode* newtre = new TreeNode(val);
            return newtre;
        }
        
        // root->left = insertIntoBST做到了二叉树的连接
        if (root->val > val) root->left = insertIntoBST(root->left, val); 
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};