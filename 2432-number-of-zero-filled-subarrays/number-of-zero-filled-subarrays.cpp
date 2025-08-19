class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, streak = 0;

        for (int x : nums) {
            if (x == 0) {
                streak++;      
                ans += streak;  
            } else {
                streak = 0;     
            }
        }
        return ans;
    }
};
