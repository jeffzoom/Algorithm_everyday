class Solution {
public:
    string replaceSpace(string s) {
        int numk = 0;
        int soldsize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                // 要扩充，s[i]只能容得下一个字符
                // s[i] = '%20'; // 这个不对
                numk++;
            }
        }
        s.resize(s.size() + numk * 2, 0); // 用考虑\0吗
        for (int i = soldsize - 1, j = s.size() - 1; i >= 0; i--, j--) {
            if (s[i] != ' ') { // 这个其实也是双指针方法，i慢j快，i在前面（左边），j追赶i
                s[j] = s[i];
            } else if (s[i] == ' ') {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};