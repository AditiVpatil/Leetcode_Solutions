class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int target, vector<int> &nums) {
        if(target == 0) return true;

        if(i == nums.size()) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool notPick = solve(i + 1, target, nums);

        bool pick = false;
        if(nums[i] <= target)
            pick = solve(i + 1, target - nums[i], nums);

        return dp[i][target] = pick || notPick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;

        if(sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();

        dp.assign(n, vector<int>(target + 1, -1));

        return solve(0, target, nums);
    }
};
