/*
//超出时间复杂度 我透
class Solution {
public:
    //超出时间复杂度 我透
    vector<vector<int>> generateMatrix(int n) {
        int x = 0, y = 0;
        int i1 = n - 1, i2 = n - 1, i3 = n - 1, i4 = n - 1;
        // int insertNum = 1;
        vector<vector<int>> squareOut(n, vector<int>(n, 0));
        if (n == 1) {
            squareOut[x][y] = 1;
            return squareOut;
        }
        for (int insertNum = 1; insertNum <= n * n; ) {
            for (int j = 0; j < i1; j++) {
                squareOut[x][y] = insertNum;
                insertNum++;
                y++;
            }
            if (insertNum >= n * n) break;
            i1 /= 2;
            
            for (int j = 0; j < i2; j++) {
                squareOut[x][y] = insertNum;
                insertNum++;
                x++;
            }
            i2 /= 2;
            for (int j = 0; j < i3; j++) {
                squareOut[x][y] = insertNum;
                insertNum++;
                y--;
            }
            i3 /= 2;
            for (int j = 0; j < i4; j++) {
                squareOut[x][y] = insertNum;
                insertNum++;
                x--;
            }
            x++;
            y++;
            i4 /= 2;
        }
        return squareOut;
    }
};
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 按圈数循环
        int x = 0, y = 0; // 数组下标
        int starx = 0, stary = 0; // 每次循环完一圈开始的位置，[0][0] [1][1] [2][2]
        int loop = n / 2; // 循环圈数
        int lengthxy = n - 1; // 每次循环的一边长度
        int insertNum = 1; // 要在数组里插入的元素
        vector<vector<int>> squareOut(n, vector(n, 0));

        // while (insertNum <= n * n)
        while (loop --) {
            /*
            for (int i = 0; i < lengthxy; i++) {
                squareOut[x][y++];
                insertNum ++;
            }
            for (int i = 0; i < lengthxy; i++) {
                squareOut[x++][y];
                insertNum ++;
            }
            for (int i = 0; i < lengthxy; i++) {
                squareOut[x][y--];
                insertNum ++;
            }
            for (int i = 0; i < lengthxy; i++) {
                squareOut[x--][y];
                insertNum ++;
            }*/

            x = starx;
            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (y = stary; y < lengthxy; y++) {
                squareOut[starx][y] = insertNum++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (; x < lengthxy; x++) {
                squareOut[x][y] = insertNum++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; y > stary; y--) {
                squareOut[x][y] = insertNum++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; x > starx; x--) {
                squareOut[x][y] = insertNum++;
            }
            starx ++;
            stary ++;
            lengthxy -= 1; // 不是-2，是-1，因为每次循环完一圈开始的位置starx，stary也+1，所以就相当于加了2，上面那个超出时间复杂度的算法+2是因为把lengthxy当成了每次循环的次数
        }
        if (n % 2) {
            squareOut[n / 2][n / 2] = insertNum;
        }
        return squareOut;
    }
};

