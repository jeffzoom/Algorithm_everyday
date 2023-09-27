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
class Solution {
public:
    void midlr(TreeNode* root, unordered_map<int, int> &mapintree) {
        if (root == nullptr) return;    // 前序遍历终止条件
        mapintree[root->val]++;         // 中
        midlr(root->left, mapintree);   // 左
        midlr(root->right, mapintree);  // 右
        return;
    }
    // 二元谓词
    bool static cmp(const pair<int, int> &p1, const pair<int, int> &p2) { 
        return p1.second > p2.second; //从大到小排序
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mapintree;
        midlr(root, mapintree); // 前序遍历

        vector<pair<int, int>> vec(mapintree.begin(), mapintree.end());
        sort(vec.begin(), vec.end(), cmp); 
        // 众数出现频率排序，相当于自定义map容器中pair的顺序
        // 错误1：reference to non-static member function must be called
        // 所以说cmp二元谓词要加static，不然会报错误1

        // 找出现频率最高的元素，vec[].second已经按从大到小的顺序排列了
        // 错误2：下面if判断中谓词不能用second()，加括号会报错
        vector<int> result;
        result.push_back(vec[0].first);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == vec[0].second) {
                result.push_back(vec[i].first);
            }
            else break;
        }
        return result;
    }
};
