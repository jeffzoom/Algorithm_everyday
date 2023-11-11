/*
dp[i] : 字符串长度为i的话，dp[i]为true表示可以拆分为一个或多个在字典中出现的单词。
判断：if([j,i] == wordDict[] && dp[j] == true)
先遍历背包 先for背包
*/
// class Solution { // 37 / 46 个通过的测试用例 不行 思路不对
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
//         vector<bool> dp(s.size() + 1, false); 
//         // 背包无容量就最大初始化dp，背包有容量就用背包容量初始化dp
//         dp[0] = true;

//         for (int i = 0; i < s.size(); i++) {
//             for (int j = 0; j < wordDict.size(); j++) {
//                 // substr(起始位置，截取的个数)
//                 string tmp = s.substr(i, wordDict[j].size());
//                 if (find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end() && dp[i] == true) {
//                     auto a = find(wordDict.begin(), wordDict.end(), tmp);
//                     dp[i + (*a).size()] = true;
//                     i += wordDict[j].size() - 1;
//                     break;
//                 }
//             }
//         }
//         return dp[s.size()];
//     }
// };


/*
dp[i] : 字符串长度为i的话，dp[i]为true表示可以拆分为一个或多个在字典中出现的单词。
判断：if([j,i] == wordDict[] && dp[j] == true)
先遍历背包 先for背包
从j到i这一段
*/
// 这个题真难想
class Solution { 
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false); 
        // 背包无容量就最大初始化dp，背包有容量就用背包容量初始化dp
        dp[0] = true;

        // dp[i] : s字符串长度为i的话，dp[i]为true表示可以拆分为一个或多个在字典中出现的单词。
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) { // 这个j是为了下面的截取操作
                // 重点 j 不能超过 i
                
                // 判断：if([j,i] == wordDict[] && dp[j] == true)
                // 所以截取的长度就是i-j嘛，[j,i]
                string tmp = s.substr(j, i - j); // substr(起始位置，截取的个数) 
                if (wordSet.find(tmp) != wordSet.end() && dp[j] == true) {
                    dp[i] = true;  
                }
            }
        }
        return dp[s.size()];
    }
};