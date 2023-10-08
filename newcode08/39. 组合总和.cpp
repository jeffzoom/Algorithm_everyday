// class Solution {
// public:
//     vector<vector<int>> results;
//     vector<int> path;
//     set<vector<int>> tmpsults;

//     int fucksum(vector<int> &path) {
//         int fuckn = 0;
//         for (auto i : path) fuckn += i;
//         return fuckn;
//     }

//     void hhhwhatever(vector<int>& candidates, int target) {
//         if (fucksum(path) == target) {
//             vector<int> tmppath = path;
//             sort(tmppath.begin(), tmppath.end());
//             tmpsults.insert(tmppath);
//             return;
//         } else if (fucksum(path) > target) {
//             return;
//         }
//         for (int i = 0; i < candidates.size(); i++) {
//             path.push_back(candidates[i]);
//             hhhwhatever(candidates, target);
//             path.pop_back();
//         }
//         return;
//     }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         hhhwhatever(candidates, target);
//         for (auto s : tmpsults) results.push_back(s);
//         return results;
//     }
// };

// https://code-thinking-1253855093.file.myqcloud.com/pics/20201223170809182.png
// 图片版 + 剪枝
class Solution {
public:
    vector<vector<int>> results;
    vector<int> path;

    void hhhwhatever(vector<int>& candidates, int target, int sum, int idex) {
        if (sum == target) {
            results.push_back(path);
            return;
        } else if (sum > target) {
            return;
        }
        for (int i = idex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            hhhwhatever(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        hhhwhatever(candidates, target, 0, 0);       
        return results;
    }
};
