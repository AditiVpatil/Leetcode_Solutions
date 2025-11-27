class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);

        for (int i = 0; i < n; i++)
            pref[i+1] = pref[i] + nums[i];

        long long ans = LLONG_MIN;
        vector<long long> best(k, LLONG_MAX); 

        best[0] = 0; 

        for (int i = 1; i <= n; i++) {
            int mod = i % k;

            if (best[mod] != LLONG_MAX)
                ans = max(ans, pref[i] - best[mod]);

            best[mod] = min(best[mod], pref[i]);
        }

        return ans;
    }
};
