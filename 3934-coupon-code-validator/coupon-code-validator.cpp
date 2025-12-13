class Solution {
public:
    
    bool isValidCode(string &s) {
        if (s.empty()) return false;

        for (char c : s) {
            if (!(isalnum(c) || c == '_')) {
                return false;
            }
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        int n = code.size();

        vector<string> order = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        unordered_set<string> validBL(order.begin(), order.end());

        map<string, vector<string>> mp;

        for (int i = 0; i < n; i++) {
            if (isActive[i] &&
                isValidCode(code[i]) &&
                validBL.count(businessLine[i])) {

                mp[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> ans;

        for (string bl : order) {
            if (mp.count(bl)) {
                sort(mp[bl].begin(), mp[bl].end());
                for (string c : mp[bl]) {
                    ans.push_back(c);
                }
            }
        }

        return ans;
    }
};
