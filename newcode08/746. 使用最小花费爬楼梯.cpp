class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int mincost = 0;
        vector<int> dp{0, 0};
        if (cost.size() == 2) return min(cost[0], cost[1]);

        for (int i = 2; i < cost.size() + 1; i++) {
            dp.push_back( min( (*(dp.end() - 2) + cost[i - 2]), (*(dp.end() - 1) + cost[i - 1]) ));
        }

        return *(dp.end() - 1);

    }
};
