class Solution {
public:
    vector<vector<int>> results;
    vector<int> path;
    int sumpath(vector<int> &path) {
        int sump = 0;
        for (auto a : path) {
            sump += a;
        }
        return sump;
    }
    void combineiii(int k, int n, int indx) {
        if (path.size() == k && sumpath(path) != n) {
            return;
        } else if (path.size() == k && sumpath(path) == n) {
            results.push_back(path);
            return;
        }
        for (int i = indx; i <= 9; i++) {
            path.push_back(i);
            combineiii(k, n, i + 1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // 在1-9中选k个，和为n
        // k是深度

        combineiii(k, n, 1);
        return results;
    }
};
