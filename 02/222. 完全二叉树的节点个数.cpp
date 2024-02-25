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

 // 层序遍历
class Solution {
public:
    void deepord(vector<vector<int>> &vec, TreeNode* root, int deep) {
        if (root == nullptr) return;
        if (deep == vec.size()) vec.push_back(vector<int>());
        vec[deep].push_back(root->val);
        deepord(vec, root->left, deep + 1);
        deepord(vec, root->right, deep + 1);
        return;
    }
    int countNodes(TreeNode* root) {
        vector<vector<int>> vec;
        int deep = 0;
        deepord(vec, root, deep);

        int results = 0;
        for (int i = 0; i < vec.size(); i++) {
            results += vec[i].size();
        }
        return results;
    }
};

class Solution {
private:
    int getNodesNum(TreeNode* cur) {
        if (cur == NULL) return 0;
        int leftNum = getNodesNum(cur->left);      // 左节点的高度
        int rightNum = getNodesNum(cur->right);    // 右节点的高度
        int treeNum = leftNum + rightNum + 1;      // 中
        return treeNum;
    }
public:
    int countNodes(TreeNode* root) {
        return getNodesNum(root);
    }
};