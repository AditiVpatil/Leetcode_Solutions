class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i + k <= n; i++) {
            // count frequency of elements in current subarray
            map<int, int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // make vector of {value, frequency}
            vector<pair<int, int>> v;
            for (auto p : freq) {
                v.push_back({p.first, p.second});
            }

            // sort by frequency (desc), then by value (desc)
            sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            });

            // take top x and find sum
            int sum = 0;
            for (int j = 0; j < x && j < v.size(); j++) {
                sum += v[j].first * v[j].second;
            }

            res.push_back(sum);
        }

        return res;

    }
};