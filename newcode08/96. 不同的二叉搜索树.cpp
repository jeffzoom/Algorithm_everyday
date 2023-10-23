/*
看了题解，我现在不看题解大致想一下
dp[n]是n个元素组合成二叉搜索树的种类
https://code-thinking-1253855093.file.myqcloud.com/pics/20210107093226241.png
dp[3] = dp[0] * dp[2] + dp[1] * dp[1] + dp[2] * dp[0] 不懂这个公式就看上面的图
dp[n] = dp[0] * dp[n - 1] + dp[1] * dp[n -2] + ... + dp[n - 2] * dp[1] + dp[n - 1] * dp[0]
这不是杨辉三角吗，类似杨辉三角
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp{1, 1, 2, 5}; // 注：dp[0] = 1，这个是因为节点一侧没有子树，这个“没有子树”本身也算是一种情况
        if (n <= 3) return dp[n];
        dp.insert(dp.end(), n - 3, 0);
        for (int i = 4; i < n + 1; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
        
    }
};
