class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        dfs(0, candidates, target, curr, res);
        return res;
    }

    void dfs(int start, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // Break if the current number exceeds the target
            if (candidates[i] > target) break;

            curr.push_back(candidates[i]);
            dfs(i + 1, candidates, target - candidates[i], curr, res); // Use each number once
            curr.pop_back(); // Backtrack
        }
    }
};
