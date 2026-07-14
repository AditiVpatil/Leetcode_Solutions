class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int dfs(int i, int g1, int g2, vector<int>& nums) {
        if (i == nums.size())
            return (g1 && g1 == g2);

        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        long long ans = 0;

        // Don't take nums[i]
        ans += dfs(i + 1, g1, g2, nums);

        // Put in seq1
        ans += dfs(i + 1,
                   g1 == 0 ? nums[i] : gcd(g1, nums[i]),
                   g2, nums);

        // Put in seq2
        ans += dfs(i + 1,
                   g1,
                   g2 == 0 ? nums[i] : gcd(g2, nums[i]),
                   nums);

        return dp[i][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        dp.assign(nums.size(),
                  vector<vector<int>>(mx + 1,
                  vector<int>(mx + 1, -1)));

        return dfs(0, 0, 0, nums);
    }
};