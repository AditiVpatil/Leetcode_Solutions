class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        string t = "1" + s + "1";

        vector<pair<char, int>> ans;

        for (char c : t) {
            if (ans.empty() || ans.back().first != c)
                ans.push_back({c, 1});
            else
                ans.back().second++;
        }

        int best = 0;

        for (int i = 1; i + 1 < (int)ans.size(); i++) {
            if (ans[i].first == '1' &&
                ans[i - 1].first == '0' &&
                ans[i + 1].first == '0') {

                best = max(best, ans[i - 1].second + ans[i + 1].second);
            }
        }

        return ones + best;
    }
};