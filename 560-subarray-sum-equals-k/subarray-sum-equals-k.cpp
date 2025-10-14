class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;  // stores prefixSum -> frequency
    mp[0] = 1;  // base case: one way to get sum 0 (empty subarray)

    int prefixsum = 0;  // running sum
    int cnt = 0;        // count of valid subarrays

    for(int i = 0; i < nums.size(); i++) {
        prefixsum += nums[i];  

        int rem = prefixsum - k;  // what we want to find in the past

        cnt += mp[rem];  // add how many times 'rem' has appeared so far

        mp[prefixsum]++; // store current prefix sum for future use
    }

    return cnt;
}

};