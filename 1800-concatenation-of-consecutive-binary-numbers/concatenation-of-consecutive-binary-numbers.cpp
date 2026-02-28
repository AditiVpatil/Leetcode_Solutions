class Solution {
public:
    const int MOD = 1e9 + 7;
    
    
    long long solve(int n, long long ans) {
        if(n == 0) return ans;
        
     
        ans = solve(n - 1, ans);
        
     
        int bits = log2(n) + 1;
        
        
        ans = ((ans << bits) % MOD + n) % MOD;
        
        return ans;
    }
    
    int concatenatedBinary(int n) {
        return solve(n, 0);
    }
};