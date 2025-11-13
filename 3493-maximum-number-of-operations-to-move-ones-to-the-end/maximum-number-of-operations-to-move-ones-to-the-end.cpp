class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        long long ones = 0, ops = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1') ones++;
            if (s[i] == '1' && s[i + 1] == '0') {
                ops += ones;
            }
        }

        return (int)ops;
    }
};
