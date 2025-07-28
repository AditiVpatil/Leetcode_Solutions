class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(0, nums, curr, res);
        return res;
    }

    void dfs(int indx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        if (indx == nums.size()) {
            res.push_back(curr);
            return;
        }

        // Include nums[indx]
        curr.push_back(nums[indx]);
        dfs(indx + 1, nums, curr, res);

        // Exclude nums[indx]
        curr.pop_back();
        dfs(indx + 1, nums, curr, res);
    }
};
