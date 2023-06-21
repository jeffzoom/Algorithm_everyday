// dp如果是二维的话，初始化的时候第一行第一列要先有值
// dp[i]

/* 转化成背包问题，因为nums没有重量，所以说就是一维dp
背包的体积为sum / 2
背包要放入的商品（集合里的元素）重量为 元素的数值，价值也为元素的数值
背包如果正好装满，说明找到了总和为 sum / 2 的子集。
背包中每一个元素是不可重复放入。
*/

// 01背包中，dp[j] 表示： 容量为j的背包，所背的物品价值最大可以为dp[j]。

// 价值 dp[j] = max()
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) sum += n;
        if (sum % 2 == 1) return false;
        int target = sum / 2;

        // dp[i]中的i表示背包内总和
        // 题目中说：每个数组中的元素不会超过 100，数组的大小不会超过 200
        // 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
        vector<int> dp(10001, 0); 
        // 不能是 target 个0，因为 背包无容量就最大初始化dp，背包有容量就用背包容量初始化dp
        
        // 方法1：下标从0到target，这样不行，元素会重复使用，所以说方法一错误，只能从大到小来
        // 初始化
        // for (int j = nums[0]; j <= target; j++) dp[j] = nums[0];
        // for (int i = 1; i < nums.size(); i++) {
        //     for(int j = 0; j <= target; j++) {
        //         if (j - nums[i] >= 0)
        //             dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        //     } 
        //     //  max中逗号左边的dp[j]相当于差分方程里上一时刻的dp[j]
        // }

        // 方法2：下标从target到0，这样不行，元素会重复使用
        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) { 
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if (dp[target] == target) return true;
        return false;
        
    }
};

// // 用模板
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for (auto n : nums) sum += n;
//         if (sum % 2 == 1) return false;
//         int target = sum / 2;

//         // 模板要用到的变量
//         vector<int> weight = nums;
//         vector<int> value = nums;
//         int bagweight = target;

//         // 模板开始
//         // 二维数组
//         vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));
//         // 初始化
//         for (int j = weight[0]; j <= bagweight; j++) {
//             dp[0][j] = value[0];
//         }
//         // weight数组的大小 就是物品个数
//         for(int i = 1; i < weight.size(); i++) { // 遍历物品
//             for(int j = 0; j <= bagweight; j++) { // 遍历背包容量
//                 if (j < weight[i]) 
//                     dp[i][j] = dp[i - 1][j];
//                 else 
//                     dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]); 
//                     // 这一步保证了元素不会重复使用，因为使用的是dp[i - 1]的，也就是上一时刻的值
//                     // 上一时刻肯定用不到weight[i]
//             }
//         }
//         // 模板结束 dp[weight.size() - 1][bagweight]就是最终的值

//         if (dp[weight.size() - 1][bagweight] == target) return true;
//         return false;
//     }
// };
