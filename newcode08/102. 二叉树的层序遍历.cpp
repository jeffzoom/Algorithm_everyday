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

// 这个层序遍历，跟前序遍历好像
// class Solution {
// public:
//     void leveltree(int deep, TreeNode* roo, vector<vector<int>>& vec) {
//         if (roo == nullptr) return;
//         if (vec.size() == deep) vec.push_back(vector<int>()); // 推入一个空的，这咋还要推入空的呢
//         vec[deep].push_back(roo->val);
//         leveltree(deep + 1, roo->left, vec);
//         leveltree(deep + 1, roo->right, vec);
//     }
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         int levfi = 0;
//         vector<vector<int>> outvec;
//         leveltree(levfi, root, outvec);
//         return outvec;
//     }
// };




//重新做

// 这个层序遍历，跟前序遍历好像
class Solution {
public:
    void levOrd(vector<vector<int>> &vec, int lev, TreeNode* roo) {
        if (roo == nullptr) return;

        if(vec.size() == lev) vec.push_back(vector<int>()); 
        // 在20和7的时候多推入了一个vector<int>，这一行的目的是现在第lev号下标没有vector<int>，要插入
        // 这个也就是为什么[3,9,null,10,null,null,null]这个树能通过
        // 也不能是 vec.size() - 1 != lev ，[1,2,3,4,5]这样右侧树就是 3-1!=1
        // 所以是 1个==1层 2==2 这样条件才能推入

        vec[lev].push_back(roo->val);
        levOrd(vec, lev + 1, roo->left);
        // 第一次到达，lev重新变成0
        levOrd(vec, lev + 1, roo->right);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        int lev = 0;
        if (root == nullptr) return vec;
        levOrd(vec, lev, root);
        return vec;
    }
};

















