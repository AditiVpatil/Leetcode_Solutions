class Solution {
public:
    int maximumCount(vector<int>& nums) {
       int negatives = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int positives = nums.end() - lower_bound(nums.begin(), nums.end(), 1);

        return max(negatives, positives);
          
      
    }
};