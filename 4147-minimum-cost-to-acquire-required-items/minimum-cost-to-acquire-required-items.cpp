class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = LLONG_MAX;

        long long x1 = 0;
        long long x2 = min(need1, need2);
        long long x3 = max(need1, need2);

        // case x = 0
        ans = min(ans,
            1LL * x1 * costBoth +
            1LL * need1 * cost1 +
            1LL * need2 * cost2
        );

        // case x = min
        ans = min(ans,
            1LL * x2 * costBoth +
            1LL * (need1 - x2) * cost1 +
            1LL * (need2 - x2) * cost2
        );

        // case x = max
        ans = min(ans,
            1LL * x3 * costBoth +
            1LL * max(0LL, need1 - x3) * cost1 +
            1LL * max(0LL, need2 - x3) * cost2
        );

        return ans;
    }
};
