// 从代码中可以看出我用了一个index来控制饼干数组的遍历，遍历饼干并没有再起一个for循环，而是采用自减的方式，这也是常用的技巧。

// 有的同学看到要遍历两个数组，就想到用两个for循环，那样逻辑其实就复杂了。

// 大胃口先吃大饼干   从大到小  第一个for是胃口
// 小饼干先喂饱小胃口 从小到大  第一个for是饼干
// 别的方法不行

// class Solution { // 超出时间限制 18 / 21 个通过的测试用例
// public:
//     // g是孩子 s是饼干
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         int results = 0;
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         reverse(g.begin(), g.end());
//         reverse(s.begin(), s.end());

//         if (g.size() == 0) return results;
//         if (s.size() == 0) return results;

//         for (int i = 0; i < g.size(); i++) {
//             for (int j = 0; j < s.size(); j++) {
//                 // vector<int>::iterator sitreator = find(s.begin(), s.end(), g[i] + j);
//                 int children1 = g[i];
//                 auto sitreator = find_if(s.begin(), s.end(), 
//                         [children1] (const int &cookie1) {return cookie1 >= children1;} );
//                 if (sitreator != s.end()) {
//                     results++;
//                     s.erase(sitreator);
//                     break;
//                 }
//             }
//         }
        
//         return results;
//     }
// };

// 两个for变一个for 牛逼
// 从代码中可以看出我用了一个index来控制饼干数组的遍历，遍历饼干并没有再起一个for循环，而是采用自减的方式，这也是常用的技巧。
// 有的同学看到要遍历两个数组，就想到用两个for循环，那样逻辑其实就复杂了。

// 大胃口先吃大饼干   从大到小  第一个for是胃口
// 小饼干先喂饱小胃口 从小到大  第一个for是饼干
// 别的方法不行
class Solution { // 超出时间限制 18 / 21 个通过的测试用例
public:
    // g是孩子 s是饼干
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int results = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        vector<int> children1(g), cookie1(s);

        int indexcookie = cookie1.size() - 1;
        for (int i = children1.size() - 1; i >= 0; i--) {
            if (indexcookie >= 0 && cookie1[indexcookie] >= children1[i]) {
                indexcookie--;
                results++;
            }
        }
        return results;
    }
};