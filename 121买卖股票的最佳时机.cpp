/*
dp[i] 第i天能获取的最大利润为dp[i] i从0天开始算
*/
// class Solution { // 超时了 fuck 198 / 211 个通过的测试用例
// public:
//     int maxProfit(vector<int>& prices) {
//         vector<int> dp(prices.size(), 0); 
//         int result = 0;
//         for (int i = 0; i < prices.size(); i++) {
//             for (int j = 0; j < i; j++) {
//                 dp[i] = max(dp[i], prices[i] - prices[j]);
//                 result = max(result, dp[i]); // 最大值不一定在dp最后一个位置出现
//             }
//         }
//         return result;
//     }
// };

class Solution { // 贪心
public:
    int maxProfit(vector<int>& prices) {
        
        int result = 0;
        int minpi = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            
            minpi = min(minpi, prices[i]); // 取prices[i]左边的最小价格
            result = max(result, prices[i] - minpi); 
            
        }
        return result;
    }
};