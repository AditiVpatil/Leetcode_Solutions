class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(0, candidates, target, curr, res);
        return res;
    }

    void dfs(int indx, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (indx >= candidates.size() || target < 0) {
            return;
        }

        // Include current element
        curr.push_back(candidates[indx]);
        dfs(indx, candidates, target - candidates[indx], curr, res);
        curr.pop_back(); // Backtrack

        // Exclude current element
        dfs(indx + 1, candidates, target, curr, res);
    }
};
