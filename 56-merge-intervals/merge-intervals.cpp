class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        
        
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n; i++) {
            
            if (i < n-1 && intervals[i][1] >= intervals[i+1][0]) {
                intervals[i+1][0] = min(intervals[i][0], intervals[i+1][0]);
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            } else {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return ans;
    }
};
