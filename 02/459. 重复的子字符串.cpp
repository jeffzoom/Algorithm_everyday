// class Solution { //全错了，不能创建一个新串，然后对比，用双指针法
// public:
//     bool repeatedSubstringPattern(string s) {
//         int fak = 0;
//         string tmps;
//         tmps.push_back(s[0]);
//         for (int i = 0; i < s.size() / 2 + 2; i++) {
//             if (s[i] != tmps[0]) tmps.push_back(s[i]);
//             else if (s[i] == tmps[0] && i != 0) { // 第一个相等
//                 fak = 0;
//                 for (int j = i; j < s.size(); j++) {
//                     if (s[j] != tmps[j % i]) {
//                         tmps.push_back(s[i]);
//                         fak = -1;
//                         break;
//                     }   
//                 }
//                 if (fak != -1) return true;
//             }
//             else if (s[i] == tmps[0] && i == 0) {
//                 for (int j = i; j < s.size(); j++) {
//                     if (s[j] != tmps[0]) {
//                         tmps.push_back(s[i]);
//                         fak = -1;
//                         break;
//                     }   
//                 }
//                 if (fak != -1) return true;
//             }
//         }
//         return false;
//     }
// };

// class Solution { //全错了，用双指针法，通过了
// public:
//     bool repeatedSubstringPattern(string s) { 
//         int slow = 0, fast = 1;
//         int fak = 0;
//         int tmpslow, tmpfast;
//         while (fast < s.size() / 2 + 1) {
//             if (s[0] != s[fast]) fast++;
//             else {
//                 fak = 0, tmpslow = 0, tmpfast = fast;
//                 while (tmpfast < s.size()) {
//                     if (s[tmpslow % fast] != s[tmpfast]) {
//                         fak = -1;
//                         break;
//                     }
//                     tmpslow++, tmpfast++;
//                 }
//                 //if (fak != -1) return true;// 也不对 如果是半循环aabaabaa，aabaaba这样，也会输出true，该死
//                 // 下面这样就对了，暴力双指针
//                 if (fak != -1 && s.size() % fast == 0) return true;
//                 fast++;
//             }
//         }
//         return false;
//     }
// };

// class Solution { //用STL查找算法，聪明
// public:
//     bool repeatedSubstringPattern(string s) {
//         string t = s + s;
//         t.erase(t.begin()); t.erase(t.end() - 1); // 掐头去尾
//         if (t.find(s) != std::string::npos) return true; // 未找到，返回npos
//         return false;
//     }
// };


class Solution { // kmp
public:
    bool repeatedSubstringPattern(string s) {
        
    }
};
