// 牛逼，通过这道题我熟悉了一下谓词，还有优先级队列，也就是大顶堆 小顶堆，还有pair
// 在用的过程中学，这种感觉真爽，学的好快这样
class Solution { 
// 二元谓词
public:
    class mycompar {
    public:
        // bool operator()(pair<int, int>right, pair<int, int>left) { // 这个也行 但是下面的更好
        bool operator()(const pair<int, int>& right, const pair<int, int>& left) {
            return right.second > left.second; // 小顶堆先弹出的是最小的
        }
    };
public:
    bool mycompar2(const pair<int, int>& right, const pair<int, int>& left) {
        return right.second > left.second; 
    } //为什么不可以是这种谓词啊

    vector<int> topKFrequent(vector<int>& nums, int k) { //哈希表？
        // 出现频率前 k 高
        // 不是频率大于k，那unordered_map这个数据结构就不合数了

        // 大顶堆 小顶堆，用小顶堆
        unordered_map<int, int> numap; // 无序map
        vector<int> outun;
        priority_queue<pair<int, int>, vector<pair<int,int>>, mycompar>  pr_que; // 优先级队列

         // 要统计元素出现频率
        for (int i = 0; i < nums.size(); i++) {
            numap[nums[i]]++;
        }
        // for(const auto &w : numap) {
        //     if (w.second >= k) outun.push_back(w.first);
        // }
        // return outun; // 这个是返回频率大于k的元素

        // 用固定大小为k的小顶堆，扫描所有频率的数值
        for (unordered_map<int, int>::iterator it = numap.begin(); it != numap.end(); it++) {
            pr_que.push(*it);
            if (pr_que.size() > k) pr_que.pop(); // 小顶堆先弹出的是最小的
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，
        // 所以倒序来输出到数组for (int i = k - 1; i >= 0; i--) 但下面我这样也行，因为可以按任意顺序 返回答案
        for (int i = 0; i < k; i++) {
            outun.push_back(pr_que.top().first); // 错误1：不能用pr_que.front()，因为优先级队列压根就没有这个函数
            pr_que.pop();
        }
        return outun;
    }
};