class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> res;

        for (int spell : spells) {
            // Compute the minimal potion value needed:
            long long need = (success + spell - 1) / spell; // ceiling division
            auto it = lower_bound(potions.begin(), potions.end(), need);
            int count = potions.end() - it;
            res.push_back(count);
        }
        return res;
    }
};
