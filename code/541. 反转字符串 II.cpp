class Solution {
public:
    void chag2k(string &s, int i, int j) { // 左闭右闭  
        while (i < j) {
            swap(s[i], s[j]);
            i++, j--;
        }
    }
    string reverseStr(string s, int k) { // 我的思路是先交换，留下最后一个小尾巴再判断
        int tmp = 2 * k; // 如果一开始为0，循环里面每次先判断是否剩余字符少于 k 个就不用拼接了
        while (tmp < s.size()) {
            chag2k(s, tmp - (2 * k), tmp - k - 1);
            tmp += (2 * k);
        }
        if ( (s.size() - (tmp - (2 * k))) < k) {
            chag2k(s, tmp - (2 * k), s.size() - 1);
        } else {
            chag2k(s, tmp - (2 * k), tmp - k - 1);
        }
        return s;
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
            } else {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};