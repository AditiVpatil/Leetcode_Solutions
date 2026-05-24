class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
         vector<int> res;

        int n = nums.size();
        int val = nums[0];
        int count = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] != val) {
                val = nums[i];
                count = 0;
            }

            count++;

            if (count <= k) {
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};