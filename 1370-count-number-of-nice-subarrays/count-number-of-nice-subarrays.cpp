class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, res = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] % 2 == 1) k--;   
            while (k < 0) {              
                if (nums[l] % 2 == 1) k++;
                l++;
            }
            res += (r - l + 1);          
        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
