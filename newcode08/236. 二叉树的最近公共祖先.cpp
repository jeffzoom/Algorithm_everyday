/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 我艹，这个题我有点懵，但是视频讲清楚了
// https://www.bilibili.com/video/BV1jd4y1B7E2/?vd_source=3bafe92017da0191f9e03d4d7ee36c91
// https://code-thinking-1253855093.file.myqcloud.com/pics/202102041512582.png
// 大概知道了，这个题就是可以练递归返回值
// 这道题要配合着图片和视频一起享用
class Solution {
public:
    // 1.确定参数和返回值
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
        // 2.确定终止条件
        if (root == nullptr) return nullptr; // 对应节点1 6 5 15 20 下面的空节点
        if (root->val == p->val || root->val == q->val) return root; // 对应节点5 6 返回 5 6 红圈 

        // 3.确定单层递归的逻辑 
        // 二叉树从下往上处理一定是后序遍历
        TreeNode* leftnd = lowestCommonAncestor(root->left, p, q); // 左
        TreeNode* rightnd = lowestCommonAncestor(root->right, p, q); // 右

        // 中
        if (leftnd != nullptr && rightnd != nullptr) return root; // 对应节点7

        if (leftnd != nullptr && rightnd == nullptr) return leftnd; // 懂了，真正意义上的返回节点
        // 左不为空返回左，对应的是节点8，返回7
        if (leftnd == nullptr && rightnd != nullptr) return rightnd;
        // 右不为空返回右，对应的是节点10，返回7
        return nullptr; // 对应节点4
    }
};
