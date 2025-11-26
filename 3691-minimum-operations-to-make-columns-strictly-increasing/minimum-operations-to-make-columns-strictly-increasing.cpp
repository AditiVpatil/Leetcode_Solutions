class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
    int n = grid[0].size();
    int totalOps = 0;
    for (int j = 0; j < n; j++) {
        int pre = -1; 
        for (int i = 0; i < m; i++) {
            if (grid[i][j] > pre) {
                pre = grid[i][j]; 
            } else {
                totalOps += (pre + 1 - grid[i][j]); 
                pre = pre + 1;
            }
        }
    }

    return totalOps;
    }
};