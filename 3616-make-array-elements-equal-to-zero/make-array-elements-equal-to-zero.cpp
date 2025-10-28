class Solution {
public:
    bool allZero(const vector<int>& nums) {
    for (int x : nums)
        if (x != 0) return false;
    return true;
}


bool simulate(vector<int> nums, int start, int dir) {
    int n = nums.size();
    int curr = start;

    while (curr >= 0 && curr < n) {
        if (nums[curr] == 0) {
            curr += dir;  
        } else {  
            nums[curr]--;
            dir = -dir;   
            curr += dir;  
        }
    }

    return allZero(nums);
}

int countValidSelections(vector<int>& nums) {
    int n = nums.size();
    int valid = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            
            if (simulate(nums, i, 1)) valid++;
            if (simulate(nums, i, -1)) valid++;
        }
    }
    return valid;
}
};