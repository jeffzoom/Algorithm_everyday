// dp[x][i] = dp[x-1][i-1] + dp[x-1][i]
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        dp.push_back(vector<int>{1});
        if (numRows == 1) return dp;
        dp.push_back(vector<int>{1, 1});
        if (numRows == 2) return dp;
        
        // i >= 3
        while (dp.size() < numRows) { // 3<3        0 1 2 
            dp.push_back(vector<int>{1, 1});
            for (int i = 1; dp.back().size() < dp.size(); i++) {
                // 插入元素
                dp.back().insert( dp.back().end() - 1, 
                     (* (dp.end() - 2) )[i-1] + (* (dp.end() - 2) )[i] );
            }
        }
        return dp;
    }
};