class Solution {
public:
    int minBitFlips(int start, int goal) {
        int XOR = start ^ goal;
        int ans = 0;
        
        
        while (XOR > 0) {
            ans += XOR & 1; 
            XOR >>= 1;
        }
        
        return ans;
    }
};