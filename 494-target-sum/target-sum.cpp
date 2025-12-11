class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int target, vector<int>& nums) {
        if (i == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        if (dp[i][target] != -1)
            return dp[i][target];

        int notPick = solve(i + 1, target, nums);

        int pick = 0;
        if (nums[i] <= target)
            pick = solve(i + 1, target - nums[i], nums);

        return dp[i][target] = pick + notPick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;

        if ((total + target) % 2 != 0 || (total + target) < 0)
            return 0;

        int P = (total + target) / 2;

        dp.assign(nums.size(), vector<int>(P + 1, -1));

        return solve(0, P, nums);
    }
};
