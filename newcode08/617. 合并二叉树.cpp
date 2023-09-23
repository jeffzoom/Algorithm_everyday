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

// class Solution { // 创建第三个树的复杂版
// public:
//     TreeNode* sum_mergeTrees(TreeNode* root1, TreeNode* root2) { // 1.参数 返回值
//         if (root2 == nullptr && root1 == nullptr) return nullptr; // 2.终止条件

//         TreeNode* tmproot = new TreeNode(0);
//         if (root1 == nullptr && root2 != nullptr) {
//             tmproot->val = root2->val;
//             return root2; // 错误1 这里不能返回tmproot，要是返回tmproot的话root2后面的值就丢失了
//         } else if (root1 != nullptr && root2 == nullptr) {
//             tmproot->val = root1->val;
//             return root1;
//         }
//         // 上面这些也算终止条件

//         tmproot->val = root1->val + root2->val;
        
        
//         tmproot->left = sum_mergeTrees(root1->left, root2->left);
//         tmproot->right = sum_mergeTrees(root1->right, root2->right);
//         return tmproot;
//     }
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         TreeNode* result = sum_mergeTrees(root1, root2);
//         return result;
//     }
// };

// class Solution { // 创建第三个树的简洁版
// public:
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) { // 1.参数 返回值
//         if (root1 == NULL) return root2; // 2.终止条件
//         if (root2 == NULL) return root1;
//         // 重新定义新的节点，不修改原有两个树的结构
//         TreeNode* root = new TreeNode(0);
//         root->val = root1->val + root2->val;
//         root->left = mergeTrees(root1->left, root2->left);
//         root->right = mergeTrees(root1->right, root2->right);
//         return root;
//     }
// };

class Solution { // 通过 只用两个树的版本
public:
    TreeNode* sum_mergeTrees(TreeNode* root1, TreeNode* root2) { // 1.参数 返回值
        if (root2 == nullptr && root1 == nullptr) return nullptr; // 2.终止条件


        if (root1 == nullptr && root2 != nullptr) return root2; // 这里的返回值很微妙，自己编完之后才知道怎么个返回方式
        else if (root1 != nullptr && root2 == nullptr) return root1;
        // 原来上面三行都是终止条件，也可以改成下面两行
        // if (root1 == nullptr) return root2;
        // if (root2 == nullptr) return root1;
        // 或者是下面两行
        // if (root1 == nullptr) return root2;
        // else if (root2 == nullptr) return root1;
        
        root1->val += root2->val;
        
        root1->left = sum_mergeTrees(root1->left, root2->left);
        root1->right = sum_mergeTrees(root1->right, root2->right);
        return root1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* result = sum_mergeTrees(root1, root2);
        return result;
    }
};

