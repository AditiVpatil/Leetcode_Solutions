class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int count = 1, currSum = 0;
        for (int num : nums) {
            if (currSum + num > maxSum) {
                count++;
                currSum = num;
                if (count > k) return false;
            } else {
                currSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                answer = mid;      // Try to minimize
                high = mid - 1;
            } else {
                low = mid + 1;     // Increase allowed max sum
            }
        }

        return answer;
    }
};
