class Solution {
public:
    long long maximumEnergy(vector<int>& energy, long long k) {
        long long n = energy.size();
        vector<long long> dp(n, 0);  
        long long maxi = LLONG_MIN;

       
        for (long long i = n - 1; i >= 0; i--) {
            if (i + k < n) {
                dp[i] = energy[i] + dp[i + k];
            } else {
                dp[i] = energy[i];
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
