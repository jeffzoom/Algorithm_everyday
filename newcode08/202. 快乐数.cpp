// class Solution {
// public:
//     bool isHappy(int n) { // 转string吗
//         string ns = to_string(n);
//         unordered_set<> 
//         for (int i =0; i < ns.size(); i++) {
            
//         }
//     }
// };

class Solution {
public:

    // 一次每个位置上的数字的平方和
    int getnSum(int nin) {
        int nyu = 0, nout = 0;
        while (nin) {
            nyu = nin % 10;
            nout += (nyu * nyu);
            nin = nin / 10;
        }
        return nout;
    }

    bool isHappy(int n) {
        unordered_set<int> recodesum;
        int nsum = n;
        while (nsum != 1) {
            nsum = getnSum(nsum);
            if (recodesum.find(nsum) == recodesum.end()) recodesum.insert(nsum);
            else return false ;
        }
        return true;
    }
};
