class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int p = 0, v = 0;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] &&
                nums[i] > nums[i + 1]) {
                p += nums[i];
            }
            else if (nums[i] < nums[i - 1] &&
                     nums[i] < nums[i + 1]) {
                v += nums[i];
            }
        }

        return p - v;
    }
};