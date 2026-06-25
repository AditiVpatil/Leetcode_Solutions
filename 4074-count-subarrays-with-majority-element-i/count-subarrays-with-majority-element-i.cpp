class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
           int targetCount = 0;

            for (int r = i; r < n; r++) {
                if (nums[r] == target) {
                    targetCount++;
                }
            
          int len = r - i + 1;

                if (targetCount > len / 2) {
                    cnt++;
                }  
            }
        }
        return cnt;   

    }
};