class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        if (nums[0] == 0) return "0";
        string res;
        for (int num : nums) res += to_string(num);
        return res;
    }
};
