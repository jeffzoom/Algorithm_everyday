/*
看完题解写的，感觉这个很有设计
真的是设计了一个对应本题专门的算法
https://code-thinking-1253855093.file.myqcloud.com/pics/20201222191924417.png
按照这个图片写的代码

很微妙，思路很清晰的一道题
挺有意思一道题
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> hash_vec(26, 0); // 用数组更快啊
       
        // 从 0 到 25
        int hash[26] = {0}; // i为字符，hash[i]为26个字母在s中最后出现的位置
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }

        vector<int> results;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']);  // 找到字符出现的最远边界
            if (i == right) {
                
                results.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return results;
    }
};
