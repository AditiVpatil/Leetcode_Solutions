#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        if (dividend == divisor) return 1;

        bool sign = (dividend >= 0) == (divisor >= 0); // true if both have same sign

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;

        while (n >= d) {
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            ans += 1LL << count;
            n -= d << count;
        }

        return sign ? ans : -ans;
    }
};
