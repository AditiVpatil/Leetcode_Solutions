class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> freq;
        long long res = 0;

        for (int num : nums) {
            int diff = num - reverseNum(num);
            res = (res + freq[diff]) % MOD;
            freq[diff]++;                   
        }

        return (int)res;
    }
};
