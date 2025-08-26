class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        long long maxDiag = 0, maxArea = 0;

        for (int i = 0; i < n; i++) {
            long long a = dimensions[i][0];
            long long b = dimensions[i][1];
            
            long long diagSq = a * a + b * b; 
            long long area = a * b;

            if (diagSq > maxDiag || (diagSq == maxDiag && area > maxArea)) {
                maxDiag = diagSq;
                maxArea = area;
            }
        }
        return (int)maxArea;
    }
};
