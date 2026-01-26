class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> idx, vals;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                idx.push_back(i);
                vals.push_back(nums[i]);
            }
        }

        int m = vals.size();
        if (m == 0) return nums;

        k = k % m;  

        
        rotate(vals.begin(), vals.begin() + k, vals.end());

        // Step 3: place back at original indices
        for (int i = 0; i < m; i++) {
            nums[idx[i]] = vals[i];
        }

        return nums;
    }
};
