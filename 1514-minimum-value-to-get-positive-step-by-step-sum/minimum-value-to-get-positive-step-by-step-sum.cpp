class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefix = 0;
        int minPrefix = INT_MAX;

        // compute minimum prefix sum
        for (auto x : nums) {
            prefix += x;
            minPrefix = min(minPrefix, prefix);
        }

        // if minPrefix never went below 1, start value = 1
        if (minPrefix >= 1) return 1;

        // otherwise, we need at least |minPrefix| + 1
        return 1 - minPrefix;
    }
};
