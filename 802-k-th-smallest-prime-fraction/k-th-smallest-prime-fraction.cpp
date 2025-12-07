class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        priority_queue<
            tuple<double, int, int>,
            vector<tuple<double, int, int>>,
            greater<tuple<double, int, int>>
        > pq;

        // push first fraction for every denominator
        for (int j = 1; j < n; j++) {
            pq.push({(double)arr[0] / arr[j], 0, j});
        }

        while (--k) {
            auto [val, i, j] = pq.top();
            pq.pop();

            if (i + 1 < j) {
                pq.push({(double)arr[i + 1] / arr[j], i + 1, j});
            }
        }

        auto [val, i, j] = pq.top();
        return {arr[i], arr[j]};
    }
};
