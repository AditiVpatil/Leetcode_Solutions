class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
         int n = nums.size();

        if (n <= 2) return n;

        int bit = 0;
        for (int num : nums) {
            bit |= num;
        }

        return bit + 1;
    }
};