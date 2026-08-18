class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> map;

        for (int i = 0; i < n; i++) {
            ++map[nums[i]];
        }

        if (k == nums.size()) {
            return *max_element(nums.begin(), nums.end());
        }

        if (k == 1) {
            int maxValue = -1;

            for (int i = 0; i < n; i++) {
                if (map[nums[i]] == 1 && nums[i] > maxValue) {
                    maxValue = nums[i];
                }
            }

            return maxValue;
        }

        n = n - 1;

        if (nums[0] == nums[n]) {
            return -1;
        }

        if (map[nums[0]] == 1 && map[nums[n]] == 1) {
            return max(nums[0], nums[n]);
        }

        if (map[nums[0]] == 1 && map[nums[n]] > 1) {
            return nums[0];
        }

        if (map[nums[n]] == 1 && map[nums[0]] > 1) {
            return nums[n];
        }

        return -1;
    }
};