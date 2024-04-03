// https://code-thinking-1253855093.file.myqcloud.com/pics/20201123195407907.png
// 这个图很形象，自己构建二叉树
// 第一层到第二层，i分别取1234，indx下标就从i+1开始取
// class Solution {
// public:
//     vector<vector<int>> result;
//     vector<int> path; // 用来存放符合条件单一结果
//     void whatever(int n, int k, int indx) { // indx是下标
//         if (path.size() == k) {
//             result.push_back(path);
//             return; // 在for中返回
//         }
//         for (int i = indx; i <= n; i++) { // 在 [1, n] 中取元素
//             path.push_back(i);
//             whatever(n, k, i + 1);
//             path.pop_back();
//         }
//         return;
//     }
//     vector<vector<int>> combine(int n, int k) {
//         // 取k个数，k是深度，取k个元素存入path中
//         whatever(n, k, 1);
//         return result;
//     }
// };

// 回溯的优化，就是剪枝
// https://code-thinking-1253855093.file.myqcloud.com/pics/20210130194335207.png

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path; // 用来存放符合条件单一结果
    void whatever(int n, int k, int indx) { // indx是下标
        // if是深度判断，for是宽度判断 
        if (path.size() == k) { 
            result.push_back(path);
            return; // 在for中返回
        }
        // 剪枝n - (k - path.size()) + 1
        // 哦，输入n=4，k=2的时候也可以剪枝，把取4的时候剪了，有点意思
        for (int i = indx; i <=  n - (k - path.size()) + 1; i++) { // 在 [1, n] 中取元素
            path.push_back(i);
            whatever(n, k, i + 1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        // 取k个数，k是深度，取k个元素存入path中。n是宽度
        whatever(n, k, 1);
        return result;
    }
};
