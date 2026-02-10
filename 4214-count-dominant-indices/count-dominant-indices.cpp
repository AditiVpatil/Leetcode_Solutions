class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int cnt = 0;

        for (int i = n - 1; i > 0; i--) {
            sum += nums[i];  

            if (1LL * nums[i-1] * (n - i) > sum) {
                cnt++;
            }
        }
        return cnt;
    }
};
