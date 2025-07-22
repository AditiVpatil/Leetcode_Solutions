class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
     unordered_set<int> seen;
    int l = 0, currentSum = 0, maxSum = 0;

    for (int r = 0; r < nums.size(); ++r) {
        while (seen.count(nums[r])) { //check is the element in set or not
            seen.erase(nums[l]);
            currentSum -= nums[l];
            l++;
        }
        seen.insert(nums[r]);
        currentSum += nums[r];
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
    }
};