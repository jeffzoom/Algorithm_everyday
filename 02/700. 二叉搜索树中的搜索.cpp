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

// 二叉搜索树是一个有序树：
// 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
// 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
// 它的左、右子树也分别为二叉搜索树

class Solution { // 没看题解，自己搞定的递归
public:
    TreeNode* tempsave = nullptr; // 这是一个短暂保存的节点，用于递归返回到上一层
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;

        if (root->val == val) {
            tempsave = root;
            // return root; // 都行
            return tempsave;
        }

        // 这两行并没有用搜索二叉树的性质，我直接暴力
        // searchBST(root->left, val); 
        // searchBST(root->right, val);

        // 这两行用了搜索二叉树的性质，节点左边小右边大
        else if (root->val > val) searchBST(root->left, val);
        else searchBST(root->right, val);
    
        return tempsave;
    }
};

