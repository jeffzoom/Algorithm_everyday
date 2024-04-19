class Solution {
public:
    const string numblet2to9[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };
    vector<string> results;
    string path;
    int insertbuf = 0;

    void telephonenumbcomb (string &digits, int index) {
        if (path.size() == digits.size()) {
            results.push_back(path); // 深度
            return;
        }

        // 要取index指向的数字，并找到对应的字符集，index是digits的下标
        string s = numblet2to9[digits[index] - '0']; // "abc";   "def";

        for (int i = 0; i < s.size(); i++) { // "23"
            path.push_back(s[i]); // 不对 推完abc中的a 该推def的d了
            telephonenumbcomb(digits, (index + 1) % digits.size());
            path.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return results;
        telephonenumbcomb(digits, 0);
        return results;
    }
};
