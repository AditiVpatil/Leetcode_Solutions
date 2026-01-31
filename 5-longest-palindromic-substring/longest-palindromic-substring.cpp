class Solution {
public:
    string s;
    vector<vector<int>> memo;
    int start = 0, maxLen = 1;

    bool isPal(int i, int j) {
        if (i >= j) return true;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] != s[j])
            return memo[i][j] = false;

        return memo[i][j] = isPal(i + 1, j - 1);
    }

    string longestPalindrome(string str) {
        s = str;
        int n = s.size();
        memo.assign(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPal(i, j)) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
