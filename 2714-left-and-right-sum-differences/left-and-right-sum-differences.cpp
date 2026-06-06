class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int l = 0;

        for (int i = 0; i < nums.size(); i++) {
            l += nums[i];
        }

        int r = 0;
        int n = nums.size();
        vector<int> result(n);

        for (int i = n - 1; i >= 0; i--) {
            l -= nums[i];             
            result[i] = abs(r - l);    // answer for index i
            r += nums[i];              // update right sum
        }

        return result;
    }
};