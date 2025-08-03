class Solution {
public:
    bool isStrictlyIncreasing(const std::vector<int>& nums, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (nums[i] >= nums[i + 1]) return false;
        }
        return true;
    }

    bool isStrictlyDecreasing(const std::vector<int>& nums, int start, int end) {
        for (int i = start; i < end; ++i) {
            if (nums[i] <= nums[i + 1]) return false;
        }
        return true;
    }

    bool isTrionic(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        for (int p = 1; p < n - 2; ++p) {
            if (!isStrictlyIncreasing(nums, 0, p)) continue;

            for (int q = p + 1; q < n - 1; ++q) {
                if (!isStrictlyDecreasing(nums, p, q)) continue;

                if (isStrictlyIncreasing(nums, q, n - 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};
