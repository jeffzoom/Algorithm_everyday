class Solution { //暴力通过
public:
    int strStr(string haystack, string needle) {
        int fak = 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) { //可能相等
                for (int i1 = i, j = 0; j < needle.size(); j++, i1++) {
                    if (haystack[i1] != needle[j]) {
                        fak = -1;
                        break;
                    }
                }
                if (fak != -1) return i;
                else fak = 0;
            }
        }
        return -1;
    }
};

//KMP算法里的next数组，知道了next数组就是前缀表，再分析为什么要是前缀表而不是什么其他表
// 前缀表是用来回退的，它记录了模式串与主串(文本串)不匹配的时候，模式串应该从哪里开始重新匹配。
class Solution { //KMP算法
public:
    int strStr(string haystack, string needle) {
        
    }
};
