class Solution {
public:
    bool isValid(string s) { // ()1 []2 {}3 括号匹配是使用栈解决的经典问题
        // 好神奇，栈这么有用啊，一开始没思路，看了一下题解
        // 一个好的数据结构果然可以提高效率

        // 错误1： if (s[i] == ')' && stks.top() == '(' && !stks.empty())
        // 显示： Segmentation fault（段错误），这是对内存操作不当造成的
        // 错误原因：在栈为空的时候判断if(stks.top() == '(')
        // 修改：&&是短路求值，当左侧无法确定结果的时候才计算右侧的值，
        //      所以说先判断栈是否为空，若为空就不进行第三个判断，因此调换if中后两个判断的顺序

        // 例子：stack<char> stks;
        //       if(stks.top() == '(') s.push_back('a'); // 在栈为空的时候就会报这样的错误

        stack<char> stks;
        if (s.size() % 2) return false; // 基数个直接返回
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')'  && !stks.empty() && stks.top() == '(') { // "){"会报错，为什么,
                stks.pop();
                continue;
            }
            else if (s[i] == ']' && !stks.empty()&& stks.top() == '[') {
                stks.pop();
                continue;
            } 
            else if (s[i] == '}' && !stks.empty()&& stks.top() == '{') {
                stks.pop();
                continue;
            }
            stks.push(s[i]);
        }
        if (stks.empty()) return true;
        return false; 
        
    }
};