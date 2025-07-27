class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int idx = n - 2;  
        for (int i = 0; i < n / 3; ++i) {
            sum += nums[idx];
            idx -= 2; 
        }
        return sum;
    
    }
};