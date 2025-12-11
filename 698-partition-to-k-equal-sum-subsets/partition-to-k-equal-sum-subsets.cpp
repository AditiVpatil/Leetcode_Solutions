class Solution {
public:
    bool solve(int idx, int currSum, int target, int bucket,
               vector<int> &nums, vector<int> &vis, int k) {
        
        // If we filled k-1 buckets successfully, the last one is automatically correct
        if(bucket == k-1) return true;

        // If current bucket hits target, move to next bucket
        if(currSum == target)
            return solve(0, 0, target, bucket + 1, nums, vis, k);

        // Try to pick elements starting from idx
        for(int i = idx; i < nums.size(); i++) {

            // If not used before and picking does not overflow target
            if(!vis[i] && currSum + nums[i] <= target) {
                
                // PICK
                vis[i] = 1;

                // Recurse
                if(solve(i + 1, currSum + nums[i], target, bucket, nums, vis, k))
                    return true;

                // NOT PICK (backtrack)
                vis[i] = 0;
            }
        }

        return false; 
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int x: nums) sum += x;

        if(sum % k != 0) return false; // must divide equally

        int target = sum / k;
        sort(nums.rbegin(), nums.rend()); // optimizes recursion

        vector<int> vis(nums.size(), 0);
        return solve(0, 0, target, 0, nums, vis, k);
    }
};
