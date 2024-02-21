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
class Solution { //自己做出来的
public:
    // 确定递归函数的参数和返回值 左子右子和r f
    // 确定终止条件 3个return
    // 确定单层递归的逻辑 compare(lef->left, rig->right, r, f); compare(lef->right, rig->left, r, f);
    void compare(TreeNode* lef, TreeNode* rig, int &r, int &f) {
        if (lef == nullptr && rig == nullptr) return;
        else if((lef != nullptr && rig == nullptr) || (lef == nullptr && rig != nullptr) 
                || (lef->val != rig->val)) {
            // 三种情况，分别是：左有值右空，左空右有值，左右不等
            f = 0;
            return;
        }
        compare(lef->left, rig->right, r, f);
        compare(lef->right, rig->left, r, f);
        r = 1;
        return;
    }
    bool isSymmetric(TreeNode* root) {
        int r = 0, f = 1;
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return true;
        compare(root->left, root->right, r, f);
        if (r == 1 && f == 1) return true;
        else return false;
    }
};
