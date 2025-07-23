class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        int lastSeenS[256] = {0}; // ASCII character range
        int lastSeenT[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (lastSeenS[s[i]] != lastSeenT[t[i]])
                return false;

            lastSeenS[s[i]] = i + 1;
            lastSeenT[t[i]] = i + 1;
        }

        return true;
    }
};
