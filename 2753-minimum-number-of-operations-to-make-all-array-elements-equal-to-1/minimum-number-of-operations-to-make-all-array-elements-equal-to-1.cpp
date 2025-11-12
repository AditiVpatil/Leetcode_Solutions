class Solution {
public:
    int minOperations(vector<int>& nums) {
    int n = nums.size();
    int overall = nums[0];
    for (int i = 1; i < n; i++)
        overall = gcd(overall, nums[i]);

    if (overall != 1) return -1;  

    int ones = count(nums.begin(), nums.end(), 1);
    if (ones > 0)
        return n - ones;

    int best = INT_MAX;
    for (int i = 0; i < n; i++) {
        int g = nums[i];
        for (int j = i + 1; j < n; j++) {
            g = gcd(g, nums[j]);
            if (g == 1) {
                best = min(best, j - i + 1);
                break;
            }
        }
    }

    return (best - 1) + (n - 1);
}

};