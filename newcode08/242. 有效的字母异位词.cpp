// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t;
//     }
// };

// 如果非要记录单词字母个数的话

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++; // ASCII码
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--; // ASCII码
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) { return false; }            
        }
        return true;
    }
};