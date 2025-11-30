class Solution {
public:
    int countElements(vector<int>& nums, int k) {
      int n = nums.size();
        if (k == 0) return n;
        if (k >= n) return 0;

        sort(nums.begin(), nums.end()); 

        int kthLargest = nums[n - k]; 

        int count = 0;
        for (int x : nums) {
            if (x < kthLargest) count++;
        }
        return count;
    }
};