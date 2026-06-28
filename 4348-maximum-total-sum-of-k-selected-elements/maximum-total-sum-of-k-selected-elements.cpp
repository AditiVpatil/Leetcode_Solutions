class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        long long sum = 0;
        int n = nums.size();

        for (int i = n - 1; i >= 0 && k > 0; i--, k--) {

            if (mul > 0) {
                sum += 1LL * nums[i] * mul;
                mul--;
            } else {
                sum += nums[i];
            }
        }

        return sum;
    }
};