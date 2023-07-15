// class Solution { //方法1 添加和删除
// public:
//     string reverseLeftWords(string s, int n) {
//         for (int i = 0; i < n; i++) {
//             s.push_back(s[0]);
//             s.erase(s.begin());
//         }
//         return s;
//     }
// };

class Solution { //方法2 翻转
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};