// class Solution { // 超出时间限制 172 / 176 个通过的测试用例
// public:
//     vector<vector<int>> results;
//     vector<int> path;
//     set<vector<int>> tmpsults;

//     int fucksum(vector<int> &path) {
//         int fuckn = 0;
//         for (auto i : path) fuckn += i;
//         return fuckn;
//     }

//     void hhhwhatever(vector<int>& candidates, int target, int idex) {
//         if (fucksum(path) == target) {
//             vector<int> tmppath = path;
//             sort(tmppath.begin(), tmppath.end());
//             tmpsults.insert(tmppath);
//             return;
//         } else if (fucksum(path) > target) {
//             return;
//         }
//         // 剪枝
//         for (int i = idex; i < candidates.size(); i++) {
//             path.push_back(candidates[i]);
//             hhhwhatever(candidates, target, i + 1);
//             path.pop_back();
//         }
//         return;
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         hhhwhatever(candidates, target, 0);
//         for (auto s : tmpsults) results.push_back(s);
//         return results;
//     }
// };

/////////////////////////////////////

class Solution {
public:
    vector<vector<int>> results;
    vector<int> path;

    void hhhwhatever(vector<int>& candidates, int target, int sum, 
                                              int idex, vector<bool> used) {
        if (sum == target) {
            // sort(path.begin(), path.end());
            // if (find(results.begin(), results.end(), path) == results.end()) 
                results.push_back(path);
            return;
        } else if (sum > target) {
            return;
        }

        // 宽度
        for (int i = idex; i < candidates.size() && sum + candidates[i] <= target; i++) {
// https://www.bilibili.com/video/BV12V4y1V73A/?vd_source=3bafe92017da0191f9e03d4d7ee36c91
            // candidates[i] == candidates[i - 1] 和上一个相同
            // 上一个用过
            // used[i - 1] == true是树枝去重，深度，纵向，题目允许
            // 标记回溯之后用的第二个“1”，used[i - 1] == false是树层去重，宽度，这就是要去重的目标

            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;

            used[i] = true;
            sum += candidates[i];
            path.push_back(candidates[i]);
            hhhwhatever(candidates, target, sum, i + 1, used);

            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<bool> used(candidates.size(), false);

        sort(candidates.begin(), candidates.end());
        hhhwhatever(candidates, target, 0, 0, used);       
        return results;
    }
};
