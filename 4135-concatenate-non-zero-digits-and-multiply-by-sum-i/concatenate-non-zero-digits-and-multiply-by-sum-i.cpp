class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        for (char c : to_string(n)) {
            if (c != '0') {
                x = x * 10 + (c - '0');
            }
        }
        long long sum = 0, t = x;
        while (t > 0) {
            sum += t % 10;
            t /= 10;
        }
        return x * sum;
    }
};