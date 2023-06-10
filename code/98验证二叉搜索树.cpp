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
//     // bool testreserchtree (TreeNode* root, int leftmax, int rightmax) {

//     // } 

//     // 注意[5,4,6,null,null,3,7]是false，因为右子树自身必须也是二叉搜索树。
//     // 现在没有实现的功能是判断右子树自身也是二叉搜索树，子节点要比上面的父节点大，3应该比5大才行
//     // shit 那所有的左节点也要比5小
//     bool tmpresult = true;

//     bool isValidBST(TreeNode* root) {
//         if (root->left == nullptr && root->right== nullptr) return tmpresult;
//         if (root->left != nullptr && root->left->val >= root->val) {
//             tmpresult = false;
//             return tmpresult;
//         }
//         if (root->right != nullptr && root->right->val <= root->val) {
//             tmpresult = false;
//             return tmpresult;
//         }

//         if (root->left != nullptr) isValidBST (root->left);
//         if (root->right != nullptr) isValidBST (root->right);

//         return tmpresult;   
//     }
// };

// 看完题解，这种数据结构要用中序遍历，因为是有序的
class Solution {
public:
    // 以上代码是因为后台数据有int最小值测试用例，所以都把maxVal改成了longlong最小值。
    // 如果测试数据中有 longlong的最小值，怎么办？
    // 不可能在初始化一个更小的值了吧。 建议避免 初始化最小值，如下方法取到最左面节点的数值来比较。
    
    long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
    bool tmpresult = true;

    bool isValidBST(TreeNode* root) {
        
        if (root == nullptr) return tmpresult;
        if (root->left != nullptr) isValidBST(root->left); // 左
        // 中
        if (maxVal < root->val) maxVal = root->val;
        else {
            tmpresult = false;
            return false;
        }
        
        if (root->right != nullptr) isValidBST(root->right); // 右

        return tmpresult;   
    }
};
