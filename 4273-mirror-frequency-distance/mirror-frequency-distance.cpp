class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(128, 0);   
        vector<bool> vis(128, false);

        for (char c : s) freq[c]++;

        int ans = 0;

        for (char c : s) {
            if (vis[c]) continue;

            char m;

            if (isdigit(c))
                m = '9' - (c - '0');     
            else
                m = 'z' - (c - 'a');     

            ans += abs(freq[c] - freq[m]);

            vis[c] = true;
            vis[m] = true;
        }

        return ans;
    }
};