class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();

        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        double s = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (i >= n - m) {
                s += prices[i] * (100 - discounts[i - (n - m)]) / 100.0;
            }
            else {
                s += prices[i];
            }
        }

        return s;
    }
};