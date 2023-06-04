// class Solution { // 37 / 51 个通过的测试用例，但是超出时间限制
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         stack<int> stk1;
//         vector<int> outmx;
//         for (int i = 0; i + k - 1 < nums.size(); i++) {
//             for (int j = i; j < k + i; j++) { // 将窗口中元素推入栈
//                 stk1.push(nums[j]);
//             }
//             outmx.push_back(stk1.top()); // 第一个元素推入输出数组
//             stk1.pop();
//             while (!stk1.empty()) {
//                 if (outmx[i] < stk1.top()) {
//                     outmx[i] = stk1.top();
//                 }
//                 stk1.pop(); 
//             }  
//         }
//         return outmx;
//     }
// };

// class Solution { // 不用栈了，直接判断
//                  // 37 / 51 个通过的测试用例，但是超出时间限制，还是超过吗
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> outmx;
//         for (int i = 0; i + k - 1 < nums.size(); i++) {
//             outmx.push_back(nums[i]);
//             for (int j = i + 1; j < k + i; j++) { // 将窗口中元素推入栈
//                 if (outmx[i] < nums[j]) {
//                     outmx[i] = nums[j];
//                 }
//             }
//         }
//         return outmx;
//     }
// };

class Solution { // 真不愧是hard啊
public:
    // 图片思路：
// https://code-thinking.cdn.bcebos.com/gifs/239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC-2.gif
    // 新设计一个单调队列:单调递减或单调递增的队列
    /*
    大顶堆（优先级队列）来存放这个窗口里的k个数字，这样就可以知道最大的最大值是多少了， 
    但是问题是这个窗口是移动的，而大顶堆每次只能弹出最大值，我们无法移除其他数值，
    这样就造成大顶堆维护的不是滑动窗口里面的数值了。所以不能用大顶堆
    */
    // 常用的queue在没有指定容器的情况下，deque就是默认底层容器

    class mDeqQue {
    public:
        // mDeqQue(); // 可以不用写构造函数

        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int val) {
            if (!deq.empty() && deq.front() == val) deq.pop_front();
        }

        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return deq.front();
        }

        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int val) {
            while(!deq.empty() && val > deq.back()) {
                deq.pop_back();
            }
            deq.push_back(val);
        }
    private:
        deque<int> deq;
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        mDeqQue nb_deqque;
        vector<int> outmx;
        // 先放前k个，第一个窗口
        for (int i = 0; i < k; i++) {
            nb_deqque.push(nums[i]);
        }
        outmx.push_back(nb_deqque.front());
        // 之后一个一个放
        for (int i = k; i < nums.size(); i++) {
            // 错误1：滑动窗口移除最前面元素
            // 防止元素重复 如 i=3 应该对比的是nums[0] ，而不是nums[i - 1]
            nb_deqque.pop(nums[i - k]); 

            nb_deqque.push(nums[i]);
            outmx.push_back(nb_deqque.front());
        }
        return outmx;    
    }
};
