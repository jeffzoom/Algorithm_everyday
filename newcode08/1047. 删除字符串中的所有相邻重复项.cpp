// class Solution { // 这个算法题，不就是游戏消消乐吗
// public:
//     string removeDuplicates(string s) { 
        
//         //用数据结构来解决，也就是用栈来解决，跟前面的用哈希表来解决一样
//         // "aaa" 要输出"a"，艹，我以为连着就要删呢，原来是偶数个删除
//         // "bbba"要输出"ba"

//         stack<char> st1, st2;
        
//         for (int i = 0; i < s.size(); ) {
//             if (!st1.empty() && st1.top() == s[i]) { // 发现潜在的一连串相同了
//                 while (i < s.size()  && st1.top() == s[i]) {
//                     i++;
//                 }
//                 st1.pop();
//                 continue;
//             }
//             st1.push(s[i]);
//             i++;
//         }
//         while (!st1.empty()) {
//             st2.push(st1.top());
//             st1.pop();
//         }
//         string sout;
//         while (!st2.empty()) {
//             sout.push_back(st2.top());
//             st2.pop();
//         }
//         return sout;
//     }
// };

class Solution { // 原来是假消消乐
public:
    string removeDuplicates(string s) { 
        
        //用数据结构来解决，也就是用栈来解决，跟前面的用哈希表来解决一样
        // "aaa" 要输出"a"，艹，我以为连着就要删呢，原来是偶数个删除
        // "bbba"要输出"ba"

        stack<char> st1, st2;
        
        for (int i = 0; i < s.size(); ) {
            if (!st1.empty() && st1.top() == s[i]) { // 发现潜在的一连串相同了
                
                i++;
                
                st1.pop();
                continue;
            }
            st1.push(s[i]);
            i++;
        }
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        string sout;
        while (!st2.empty()) {
            sout.push_back(st2.top());
            st2.pop();
        }
        return sout;
    }
};