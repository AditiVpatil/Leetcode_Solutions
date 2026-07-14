class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        long long resources = k;
        long long operations = 0;
        long long ans = 0;

        for (int x : nums) {
            if (resources < x) {
                long long need = x - resources;

                long long ops = (need + k - 1) / k;

                long long first = operations + 1;
                long long last = operations + ops;

                 long long a = first + last;
                 long long b = ops;

              if (a % 2 == 0)
                    a /= 2;
                  else
                     b /= 2;

           long long cost = (a % MOD) * (b % MOD) % MOD;
                ans = (ans + cost) % MOD;

                operations += ops;
                resources += ops * 1LL * k;
            }

            resources -= x;
        }

        return ans % MOD;
    }
};