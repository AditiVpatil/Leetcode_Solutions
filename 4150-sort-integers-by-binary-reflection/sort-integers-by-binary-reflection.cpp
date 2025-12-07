class Solution {
public:
    
    int reverseBinary(int x) {
        int rev = 0;
        while (x > 0) {
            rev = (rev << 1) | (x & 1);
            x >>= 1;
        }
        return rev;
    }
    
    vector<int> sortByReflection(vector<int>& nums) {
        unordered_map<int, int> mp;

        
        for (int x : nums) {
            mp[x] = reverseBinary(x);
        }

        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (mp[a] == mp[b])
                return a < b;   
            return mp[a] < mp[b];
        });

        return nums;
    }
};
