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

// 不行，自己想还是没思路，先看了看题解
// 现在理解了一点递归了，得学会自己设计二叉树的递归哦
class Solution {
public:
    // inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历
    TreeNode* buildMyTree(vector<int>& inorder, vector<int>& postorder) { // 1.确定参数和返回值
        // 2.确定终止条件
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr; // 错误1，不应该返回root
        // 因为root->left，root->right（倒数第二三行），要是inorder和postorder没有值，肯定就返回nullptr喽
        // nullptr也是指针嘛

        // 3.确定单层递归的逻辑
        int rootoftree = *(postorder.end() - 1); // 牛逼，利用了后序遍历最后一个元素是数组的根
        TreeNode* root = new TreeNode(rootoftree); // 根节点

        // 切割 inorder 中序遍历
        vector<int>::iterator itvec = find(inorder.begin(), inorder.end(), rootoftree);
        vector<int> inorderleft(inorder.begin(), itvec); // 不用判断构造出来的是否是空数组？或者越界？
        vector<int> inorderright(itvec + 1, inorder.end());
        // 切割 postorder 后序遍历
        postorder.pop_back();
        vector<int> postorderleft(postorder.begin(), postorder.begin() + inorderleft.size()); 
        // 牛逼，利用了左右数组大小相等
        vector<int> postorderright(postorder.begin() + inorderleft.size(), postorder.end()); 

        root->left = buildMyTree(inorderleft, postorderleft);
        root->right = buildMyTree(inorderright, postorderright);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 1 <= inorder.length <= 3000
        // postorder.length == inorder.length
        return buildMyTree(inorder, postorder);
    }
};
