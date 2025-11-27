class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        vector<string> ans;
        int minSum = INT_MAX;
        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }
        for (int j = 0; j < list2.size(); j++) {
            if (mp.count(list2[j])) {
                int indexSum = j + mp[list2[j]];

                if (indexSum < minSum) {
                    ans.clear();
                    ans.push_back(list2[j]);
                    minSum = indexSum;
                } else if (indexSum == minSum) {
                    ans.push_back(list2[j]);
                }
            }
        }

        return ans;
    }
};