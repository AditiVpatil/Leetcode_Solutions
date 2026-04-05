class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int, int> count;   // sum -> how many ways
        vector<int> res;

        for (int a = 1; a * a * a <= n; a++) {
            for (int b = a; a * a * a + b * b * b <= n; b++) {
                int sum = a*a*a + b*b*b;
                count[sum]++;
            }
        }

        for (auto it : count) {
            if (it.second >= 2) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};