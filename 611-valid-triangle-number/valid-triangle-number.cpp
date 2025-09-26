class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
    if (n < 3) return 0;

    sort(nums.begin(), nums.end());
    int count = 0;

    // Fix the largest side one by one
    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;

        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                //key point
                count += (j - i);
                j--;
            } else {
                i++;
            }
        }
    }

    return count;
    }
};