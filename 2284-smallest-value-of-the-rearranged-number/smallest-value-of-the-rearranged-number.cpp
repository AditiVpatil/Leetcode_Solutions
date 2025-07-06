class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        string s = to_string(abs(num));
        if (num > 0) {
            sort(s.begin(), s.end());
            // Move first non-zero digit to front
            int i = 0;
            while (s[i] == '0') i++;
            swap(s[0], s[i]);
            return stoll(s);
        } else {
            sort(s.rbegin(), s.rend());
            return -stoll(s);
        }
    }
};
