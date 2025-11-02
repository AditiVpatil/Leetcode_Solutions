class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            int prev = nums[i - 1];
            int curr = nums[i];
            
            
            if (curr - prev > 1) {
                
                for (int j = prev + 1; j < curr; j++) {
                    res.push_back(j);
                }
            }
        }

        return res;
    }
};
