class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        long long n = nums.size();
        long long q = queries.size();

        for (long long i = 0; i < q; i++) {
            long long l = queries[i][0];
            long long r = queries[i][1];
            long long k = queries[i][2];
            long long v = queries[i][3];

            for (long long idx = l; idx <= r; idx += k) {
                nums[idx] = (nums[idx] * v) % MOD;
            }
        }

        long long ans = 0;
        for (long long i = 0; i < n; i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};
