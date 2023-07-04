class Solution { //方法1
public:
    void reverseString(vector<char>& s) {
        char tmp;
        for (int i = 0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - 1 - i]);
            // tmp = s[i];
            // s[i] = s[s.size() - 1 - i];
            // s[s.size() - 1 - i] = tmp;
        }
        
    }
};

class Solution { // 方法2 迭代器
public:
    void swapchars(vector<char>::iterator left, vector<char>::iterator right) { //左闭右开
        for (int i = 0, n = right - left; i < n / 2; i++) {
            right--;
            swap(*left, *right);
            left++;
        }
    }
    void reverseString(vector<char>& s) {
        vector<char>::iterator left = s.begin();
        vector<char>::iterator right = s.end();
        swapchars(left, right);
        
    }
};