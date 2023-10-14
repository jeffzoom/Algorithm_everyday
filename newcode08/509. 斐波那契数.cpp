class Solution {
public:
    int fib(int n) { // n=2, 0 1 2
        int result = 0;
        vector<int> vec{0, 1};
        
        while (vec.size() - 1 < n) {
            vec.push_back(*(vec.end() - 1) + *(vec.end() - 2));
        }
        return vec[n];
    }
};