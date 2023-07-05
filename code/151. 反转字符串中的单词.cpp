// class Solution {
// public:
//     string reverseWords(string s) {
//         vector<char> tmp;
//         string::iterator its = s.begin();
//         // string * itbeg = s.begin();
//         string::iterator itbeg = its;
//         while (its != s.end() + 1) {  
//             if ((*its == ' ' || its == s.end()) && its != s.begin()) {
//                 // tmp.push_back(itbeg, its);
//                 tmp.insert(tmp.end(), itbeg, its);
//                 tmp.push_back(' ');
//                 its++;
//                 itbeg = its;
//             } else {
//                 its++;
//             }
//         }
//         tmp.pop_back();
        
//         string news;
//         for (int i = tmp.size() - 1; i >= 0; i--) {
//         while (i >= 0) {
//             news.push_back(tmp[i]);
//         }
//         return news; 
//     }
// };

class Solution {
public:
    // 1.移除多余空格
    void removeMoreSpace(string &s) {
        // 头
        while (s[0] == ' ') {
            s.erase(s.begin());
        }
        // 尾
         while (s[s.size() - 1] == ' ') {
            s.erase(s.end() - 1);
        }
        // 中间
        int slow = 1, fast = 2;
        while(fast < s.size() - 1) {
            if (s[fast] == ' ' && s[slow] == ' ') {
               s.erase(s.begin() + slow); 
            } else {
                slow++;
                fast++;
            }
        }

    }
    // 2.字符串反转 swap就好
    void swapchars(string::iterator left, string::iterator right) { //左闭右开
        for (int i = 0, n = (right - left); i < n / 2; i++) {
            right--;
            swap(*left, *right);
            left++;
        }
    }
    
    string reverseWords(string s) {
        // 返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格
        // 1.移除多余空格
        removeMoreSpace(s);
        
        // 2.字符串反转 swap就好
        swapchars(s.begin(), s.end());
        
        // 3.单词反转
        string::iterator slow = s.begin();
        string::iterator fast = s.begin();

        //for ( ; slow != s.end(); fast++) {
        while (slow != s.end() + 1) {
            if (*fast == ' ' || fast == s.end()) {
                swapchars(slow, fast);
                if (fast == s.end()) break;
                fast++; // 最后一个iterator越界了 
                slow = fast;
            } else {
                fast++;
            }
        }
        return s;
        // void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        // for (int i = start, j = end; i < j; i++, j--) {
        //     swap(s[i], s[j]);
        // }
        // 我的解法的最后一个iterator越界了，之后*解引用就会报错，所以说还是写成下标的形式判断更方便，
        // for (int i = 0; i <= s.size(); ++i) {}这种判断i <= s.size()就很方便
        // 写成i <= s.size()就不用if (fast == s.end()) 
    }
};